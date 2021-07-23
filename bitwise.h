#include <iostream>
#include <bit>

using namespace std;
int xorBitwise(int first, int second){
    return(first ^ second);
}

float calcPercentSimilarity(int compareArray[], int length){
    // Should calculate percent similarity between the two xored values
    int oneCount = 0;
    for(int i=0; i<length; i++){
        int currValue = compareArray[i];
        oneCount += std::__popcount(currValue);
    }
    return(oneCount/length*100);
}

int findMaxComparison(float percentSimilarityList[], int length){
    float maxValue;
    int index;

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
long int processRawString(string& unprocessed, int length){
    if(unprocessed.length() < 15){
        return(stol(unprocessed));
    }
    string fullNum;
    for(int i=0; i<length; i++){
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