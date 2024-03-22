#include <iostream>
#include <cmath>

using namespace std;

bool Inside(float x, float y, float R){
    bool cond1, cond2, cond3;
    cond1 = ((x >= -1.0 * R && x <= 0) && ( y>= 0 && y <= sqrt(pow(R,2)-pow(x, 2))));
    cond2 = ((x > 0 && x <= R/2.0) && ( y <= 0 && y >= -2.0 * x));
    cond3 = ((x > R/2.0 && x <= R) && ( y <= 0 && y >= 2.0 * (x-R)));

    return cond1 || cond2 || cond3;
} 

int main(){
    // Example of points 
    float x1 = -2.0, x2 = -5.0, y1 = 1.50, y2 = 10.0, R = 3.0;

    cout << "The output of the function Inside on (x1, y1): " << Inside(x1,y1,R) << endl;
    cout << "The output of the function Inside on (x2, y2): " << Inside(x2,y2,R) << endl;

    if (Inside(x1,y1,R)){
        cout << "Point (x1, y1) belongs to the domain!" << endl;
    } else{
        cout << "Point (x1, y1) does not belong to the domain!" << endl;
    }

    if (Inside(x2,y2,R)){
        cout << "Point (x2, y2) belongs to the domain!" << endl;
    } else{
        cout << "Point (x2, y2) does not belong to the domain!" << endl;
    }

    return 0;
}