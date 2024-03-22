#include <iostream>
using namespace std;

int find_log2(int x){ // x = 1
    if (x <= 0) return -2;
    if (x == 1) return 0;

    int exponent = 0; 
    int tchatnoe  = x;

    while(tchatnoe != 1){
        if(tchatnoe % 2 == 1 ) return -1;
        tchatnoe /= 2; // *= += -= /= %= 
        exponent ++; // ==> += 1 | -- ==> -= 1
    }

    return exponent;
}

int main(){

    int number;
    int i = 5;

    while(i > 0){
        cout << "Enter an integer: " ; cin >> number;
        cout << "Log2(" << number << ") = " << find_log2(number) << "\n\n";
        i--;
    }


    return 0;
}