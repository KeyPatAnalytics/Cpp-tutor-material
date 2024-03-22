#include "pch.h"
#include "GCD.h"

int RecursiveGCD(int numb1, int numb2) {
    if (numb1 % numb2 == 0) return numb2;
    if (numb2 % numb1 == 0) return numb1;

    if (numb1 > numb2) return RecursiveGCD(numb1 % numb2, numb2);
    return RecursiveGCD(numb1, numb2 % numb1);
}
int GCD(const int numb1, const int numb2) {
    if (numb1 % numb2 == 0) return numb2;
    if (numb2 % numb1 == 0) return numb1;


    int new_numb1, new_numb2, tmp;
    if (numb1 > numb2) {
        new_numb1 = numb1;  new_numb2 = numb2;
    }
    else {
        new_numb1 = numb2;  new_numb2 = numb1;
    }


    while (new_numb1 % new_numb2 != 0) {
        tmp = new_numb1 % new_numb2;
        new_numb1 = new_numb2;
        new_numb2 = tmp;
    }

    return new_numb2;
}