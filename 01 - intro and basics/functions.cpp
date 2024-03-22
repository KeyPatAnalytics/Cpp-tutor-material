#include <iostream>

using namespace std;

/*
 * Функция = последовательность стейтментов для получения ОПРЕДЕЛЕННОГО результата
 * 
*/

float sum(float sub1, float sub2){
    /*
    * Данная функция принимает две оценки
    *  возвращает их сумму
    */
   float sub_sum ;

   sub_sum = sub1 + sub2;

   return sub_sum; // return - является резервированное слово

   // Резервированное слово - имеет ОПРЕДЕЛЕННОЕ ЗНАЧЕНИЕ В ЯЗЫКЕ ПРОГРАММИРОВАНИЯ (с++)
   // НЕЛЬЗЯ ИСПОЛЗОВАТЬ РЕЗЕРВИРОВАННЫЕ СЛОВА В КАЧЕСТВЕ ПЕРЕМЕННЫХ

}


float square(float num){
    // Данная функция......
    return num * num;
}

// 5! = 5 x 4 x 3 x 2 x 1 = 120
int factorial(int N){
    if (N==0) return 1;
    return N * factorial(N-1);
}

// in generic way



void greeting(string name){
    cout << "Добро пожаловать " << name << "!" << endl;
}

int sumxy(float x, float y){
    return int(x + y);
}

int main(){

/*
    float math, phys, chem, info;

    float sum = math + phys + chem + info;
    float avg = sum / 4;

    float sum_math_phys = (math + phys) / 2;
    float sum_chem_info = (chem + info)/2;
*/

/* 
cout << "Start in main()" << endl;
cout << square(square(square(5.0))) + 45 << endl;
cout << "Factotial of 25 equals to " << factorial(25) << endl;
cout << "End in main()" << endl;
*/

greeting("Патачона");
cout << sum(23, 45) << endl;


return 0;
}