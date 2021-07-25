#include <iostream>
#include <fstream>
#include <algorithm>
#include "bitwise.h"

using namespace std;
struct logData{
    int length;
    int byteCount;
    string fingerprint;
};

logData parseFile(string logname){
    fstream infile;
    infile.open(logname);

    logData data;
    
    for(string line; getline(infile, line);)
    {
        if(line[0]=='D'){
            data.length = stoi(line.substr(9, string::npos));
        }
        else if(line[0] == 'F'){
            data.fingerprint = line.substr(12, string::npos);
        }
    }
    data.byteCount = count(data.fingerprint.begin(), data.fingerprint.end(), ',') + 1;
    return(data);
}

void byteSeparation(long arrayPassing[], logData metadata){
    long firstNum;
    for(int i=0; i<metadata.byteCount; i++){
        int commaCount = count(metadata.fingerprint.begin(), metadata.fingerprint.end(), ',');
        firstNum = processRawString(metadata.fingerprint, metadata.fingerprint.length(), commaCount);
        arrayPassing[i] = firstNum;
    }
}

void compareArrays(long array1[], long array2[], long returnArray[], int arrayLength){
    for(int i=0; i<arrayLength; i++){
        returnArray[i] = array1[i] ^ array2[i];
    }
}