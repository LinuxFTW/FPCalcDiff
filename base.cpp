#include <iostream>
#include <fstream>
#include <algorithm>
#include "fpcalcparse.h"

#define log1 "fp1.log"
#define log2 "fp2.log"

using namespace std;
int main(){
    logData logfile1 = parseFile(log1);
    logData logfile2 = parseFile(log2);

    long logArray1[logfile1.byteCount];
    long logArray2[logfile2.byteCount];

    byteSeparation(logArray1, logfile1);
    byteSeparation(logArray2, logfile2);

    long xorArray[logfile1.byteCount];
    compareArrays(logArray1, logArray2, xorArray, logfile1.byteCount);
    float percSim = calcPercentSimilarity(xorArray, logfile1.byteCount);
    cout << percSim << "\n";
}