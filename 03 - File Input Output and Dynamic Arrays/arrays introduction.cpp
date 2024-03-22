#include <iostream>
#include <fstream> // file stream 

using namespace std;



int main(){
const int N = 5; // переменная - константа, ЕЕ НЕЛЬЗЯ ИЗМЕНИТЬ
// cout << "Enter N = "; cin >> N;

int class_marks [10];

int sum = 0;

cout <<"Enter your 10 ratings please" << endl;

for (int i=0; i< N; i++){
    cout << "Rating " << i+1 <<": "; cin >> class_marks[i];
    sum += class_marks[i];
}

cout << "Your average score is " << 1. * sum /N << endl;


    return 0;
}
