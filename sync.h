#include <iostream>

using namespace std;
void shiftArrays(long unshiftedArray[], long shiftedArray[], int byteCount){
    // Should shift the arrays bit by bit.
    cout << byteCount << "\n";
    cout << unshiftedArray[0] << "\n";
    bool sto1 = unshiftedArray[0] & 1 > 0;
    bool sto2 = false;
    shiftedArray[0] = unshiftedArray[0] >> 1;

    for(int i = 0; i<byteCount; i++){
        cout << unshiftedArray[i] << "   ";
        // Collect the value of the last bit, ie if the number is odd or not.
        sto2 = (unshiftedArray[i] & 1) > 0;
        // Shift the long over by one
        shiftedArray[i] = unshiftedArray[i] >> 1;
        // If sto1 is true, or if the previous byte was odd,
        if(sto1){
            // Bump up by 2^32, essentially setting the byte.
            shiftedArray[i] += 2147483648;
        }
        sto1 = sto2;
        
        cout << shiftedArray[i] << "\n";
    }
}