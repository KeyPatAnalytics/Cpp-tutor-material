#include <iostream> // input ouput stream
// #include <cmath>
#include <string>

using namespace std;

// string findUser(int userID){

// }

// int Sum(int x, int y){
//     //
//     //

//     //

//     return x + y;
// }


// void changeData(int Id){
//     //
//     //
//     //
//     //
// }


// This function calculates the average price of a Macbook in Moscow
// Argumets: price1 - ...........
// price2 - ......

// return : 
float average_price(float price1, float price2){
    return (price1 + price2)/ 2;
}

int main(){

    int vozrast ;
    string name;

    char mark = 'A';



    cout << "Hello Friend ! What's your name ?" << endl;
    cin >> name;

    cout << "Welcome " << name << "!" << endl;

    cout << "How old are you? " ;
    cin >> vozrast;

    if (vozrast > 18){
        cout << "Fullage";
    }else{
        cout << "Still young !";
    }


    // float crednaya_otsenka = 79.5;
    // double pi = 3.141592;
    // char* name  = 'Oleg Sergeevich';
    bool fullAge = true;





    return 0;
}