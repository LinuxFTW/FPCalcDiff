#include <iostream>
using namespace std;

int compareBitwise(int bits1, int bits2){
    // Should compare bits1 and bits2 bitwise, to calculate fpcalc similarity
    // using xor (^) comparison.
    return(bits1 ^ bits2);
}

int shiftBitwise(string bits1){
    // Should return a form of bits1 that removes the first bit and snakes through
    // the entire sequence sliding everything up by one. There is definitely an
    // easier way to do this. You would need to create a string with all of the bits,
    // delete one, and then reparcel all of the bits back together.
}

float calcPercentSimilarity(int compareArray[], int length){
    // Should calculate percent similarity between the two xored values
    int oneCount = 0;
    for(int i=0; i<length; i++){
        int currValue = compareArray[i];
        // Find way of counting "1"s and ignoring "0"s.
    }
    return(oneCount/length);
}

short int findMaxComparison(float percentSimilarityList[]){
    // Should determine the maximum percent similarity in percentSimilarityList
    // and return the index of which one ranked the best
}

string convertToBinary(int nonBinary){
    // Should convert a 4 byte integer to a binary string
}