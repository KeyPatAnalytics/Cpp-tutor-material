#include "pch.h"
#include "Taylor.h"
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#define float_fixed(x) fixed<<setprecision(3)<<(x) 
using namespace std;

pair<double, int> Taylor(float x, double eps = 10e-6) {
    double fx = M_PI / 2;
    double C = x; // C1 = 1.0

    int n = 0;


    while (abs(C) >= eps) {
        fx -= C;
        C *= (pow(x, 2) * pow(2 * n + 1, 2) / ((2 * n + 2) * (2 * n + 3)));
        n++;
    }
    // ?? ?????????? ???????? ????????????? ? 
    // ?????????? ???????????????? ?????? ???? 
    return { fx, 2 * n };
}
void PrintResult(float a = -1., float b = 1., float dx = 0.2) {
    float x = a;
    pair<float, int> result;


    cout << "\n\n";
    cout << "\t _______________________________________________________________" << endl;
    cout << "\t|\tx\t|\tf(x)\t|\tn\t|   arccos(x)   |" << endl;
    cout << "\t ===============================================================" << endl;


    while (x <= b) {
        result = Taylor(x);
        cout << "\t|\t" << x << "\t|\t" << float_fixed(result.first) << "\t|\t"
            << result.second << "\t|\t" << float_fixed(acos(x)) << "\t|" << endl;
        x += dx;
    }
    cout << "\t _______________________________________________________________" << endl;
    cout << "\n\n";
}



int main() {

    PrintResult();

    return 0;
}