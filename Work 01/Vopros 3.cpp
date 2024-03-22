#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double R) {
    if (x <= 0) {
        return -1.0 * (0.5 * x + R);
    } else if (x <= R) {
        return -1.0 * sqrt(R * R - x * x);
    } else if (x <= 2 * R) {
        return sqrt(4 * R * x - x * x);
    } else {
        return 0;
    }
}

int main() {
    double x = 0.0; // Example input value for x
    double R = 3.0; // Example value for R
    double result = f(x, R);
    
    cout << "Result: " << result << endl;
    return 0;
}
