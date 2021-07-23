#include <iostream>
#include <fstream>
#include <algorithm>
#include "bitwise.h"

#define log1 "fp1.log"
#define log2 "fp2.log"

using namespace std;
int main(){
    fstream iofile;
    iofile.open(log1);

    int length;
    string fingerprint;
    
    for(string line; getline(iofile, line);)
    {
        if(line[0]=='D'){
            length = stoi(line.substr(9, string::npos));
        }
        else if(line[0] == 'F'){
            fingerprint = line.substr(12, string::npos);
        }
    }

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
    return(0);
}