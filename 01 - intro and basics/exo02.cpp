#include <iostream>

using namespace std;


int main(){

    // cout << "Operator + " << 4 + 8 << endl;
    // cout << "Operator - " << 4 - 8 << endl;
    // cout << "Operator * " << 4 * 8 << endl;
    // cout << "Operator // " << 7 / 2 << endl; // int / int = int
    // cout << "Operator % " << 11 % 3 << endl;
    // cout << "Operator / " << 17 / 2.0 << endl;

    int age = 23;
    int level = 5;


    // ==;  > / >=; </<=; != Логические операторы
    // && = логические ''и''
    // || = логический или
    // ! = оператор отрицания

    // true && true = true ;
    // true && false = false
    // true || false = true
    // false && false = false
    // !true = false
    // !false = true


    if( !(age >= 18) || level == 4 )
        cout << "Access granted!" << endl;
   else
    cout << "Access denied!" << endl;


    return 0;
}