#include <iostream>
#include <bit>

using namespace std;

float calcPercentSimilarity(long compareArray[], float length){
    // Should calculate percent similarity between the two xored values
    float oneCount = 0.0;
    for(int i=0; i<length; i++){
        long currValue = compareArray[i];
        // cout << std::__popcount(currValue) << "\n";
        oneCount += std::__popcount(currValue);
    }
    float percSim = (oneCount/(length*8))*100;
    return(100-percSim);
}

//Finds the maximum comparison value between every sync
int findMaxComparison(float percentSimilarityList[], int length){
    float maxValue;
    int index;

    //For every percent value in the array, if the maximum matching value is higher than the current one,
    //make the current value the maximum one.
    for(int i=0; i<length; i++){
        float currValue = percentSimilarityList[i];
        if(maxValue < currValue){
            maxValue = currValue;
            index = i;
        }
    }
    return(index);
}

// Process raw string!
long processRawString(string& unprocessed, int length, int commaCount){
    if(commaCount == 0){
        return(stol(unprocessed));
    }

    string fullNum;
    for(int i=0; i<=length; i++){
        char currChar = unprocessed[i];
        if(currChar == ','){\
            unprocessed = unprocessed.substr(i+1, string::npos);
            return(stol(fullNum));
        }
        else
        {
            fullNum = fullNum + currChar;
        } 
    }
    return(stol(fullNum));
}