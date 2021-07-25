#include <iostream>
#include <bit>

using namespace std;

float calcPercentSimilarity(long compareArray[], float length){
    // Should calculate percent similarity between the two xored values
    float oneCount = 0.0;

    // For every element in the array, get the number of ones and add it to oneCount
    for(int i=0; i<length; i++){
        long currValue = compareArray[i];
        // cout << std::__popcount(currValue) << "\n";
        oneCount += std::__popcount(currValue);
    }

    // Multiply length by 4 to get a byte count, then by 8 to get a bit count,
    // then divide oneCount by that and multiply by 100 to get a percentage.
    float percSim = (oneCount/(length*8*4))*100;
    return(100-percSim);
}

// Finds the maximum comparison value between every sync
int findMaxComparison(float percentSimilarityList[], int length){
    float maxValue;
    int index;

    // For every percent value in the array, if the maximum matching value is higher than the current one,
    // make the current value the maximum one.
    for(int i=0; i<length; i++){
        float currValue = percentSimilarityList[i];
        if(maxValue < currValue){
            maxValue = currValue;
            index = i;
        }
    }

    // Return the index of the maximum value
    return(index);
}

// Process raw string!
long processRawString(string& unprocessed, int length, int commaCount){
    // If there are no commas, this is the last integer and should be returned as is
    if(commaCount == 0){
        return(stol(unprocessed));
    }

    string fullNum;
    // For every character, if that character is a comma, then modify the rest of the
    // unprocessed string and return the number. Otherwise add the current character
    // to extend the full number.
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