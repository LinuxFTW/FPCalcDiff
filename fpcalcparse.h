#include <iostream>
#include <fstream>
#include <algorithm>
#include "bitwise.h"

using namespace std;
struct logData{
    int length; // Length is the length of the video in question
    int byteCount; // byteCount is the number of bytes
    string fingerprint; // fingerprint is the entire unmodified uncompressed fingerprint.
};

logData parseFile(string logname){
    // Generate some variables to prepare to return.
    fstream infile;
    logData data;
    
    // Open the file
    infile.open(logname);
    
    // Verify the file is open, otherwise stop the program
    if(!infile.is_open()){
        cout << "It looks like " << logname << " doesn't exist or isn't opened. \n";
        cout << "Please verify that " << logname <<  " exists before submitting an issue \n";
        exit(2);
    }
    // For every line in the string, if the first character is D that indicates duration,
    // and so the string should be sliced at character 9. Otherwise if the first character
    // is F then it should be sliced at character 12.
    for(string line; getline(infile, line);)
    {
        if(line[0]=='D'){
            data.length = stoi(line.substr(9, string::npos));
        }
        else if(line[0] == 'F'){
            data.fingerprint = line.substr(12, string::npos);
        }
    }

    // Count the number of bytes in the fingerprint, essentially getting the length of the fingerprint.
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