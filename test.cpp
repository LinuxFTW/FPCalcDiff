#include <iostream>
#include <bit>

using namespace std;
int main(){
    int a = 11953;
    int b = std::__popcount(a);
    cout << b;

}