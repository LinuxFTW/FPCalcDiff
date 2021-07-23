#include <iostream>
#include <fstream>
#include <algorithm>
#include "fpcalcparse.h"

#define log1 "fp1.log"
#define log2 "fp2.log"

using namespace std;
int main(){
    logData logfile1 = parseFile(log1);
/**
    int byteCount = count(fingerprint.begin(), fingerprint.end(), ',');
    long firstNum;
    long rawFPCalcArrayOne[byteCount]; 
    
    for(int i=0; i<byteCount; i++){
        firstNum = processRawString(fingerprint, fingerprint.length());
        rawFPCalcArrayOne[i] = firstNum;
        if(fingerprint.length()<15){
            break;
        }
    }
**/
    long byteArray[logfile1.byteCount];
    byteSeparation(byteArray, logfile1);
    for(int i=0; i<logfile1.byteCount; i++){
        cout << to_string(byteArray[i]) << "\n";
    }
}