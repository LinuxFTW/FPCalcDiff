#include <iostream>
#include <fstream>
#include <algorithm>
#include "fpcalcparse.h"
#include "sync.h"

#define log1 "fp1.log"
#define log2 "fp2.log"

using namespace std;
int main(){
    // Open both logfiles and address them to logfile1 and 2 respectively.
    logData logfile1 = parseFile(log1);
    logData logfile2 = parseFile(log2);

    // Create the arrays for both log files
    long logArray1[logfile1.byteCount];
    long logArray2[logfile2.byteCount];

    // Fill the arrays for both logfiles
    byteSeparation(logArray1, logfile1);
    byteSeparation(logArray2, logfile2);

    // Create the array for the xored values and compare the two arrays
    long xorArray[logfile1.byteCount];
    compareArrays(logArray1, logArray2, xorArray, logfile1.byteCount);


    // Determine the percent similarity for the two arrays and print it.
    float percSim = calcPercentSimilarity(xorArray, logfile1.byteCount);
    cout << percSim << "\n";

    long shiftArray[logfile1.byteCount];
    shiftArrays(logArray1, shiftArray, logfile1.byteCount);
    compareArrays(shiftArray, logArray2, xorArray, logfile1.byteCount);
    percSim = calcPercentSimilarity(xorArray, logfile1.byteCount);
    cout << percSim << "\n";
}