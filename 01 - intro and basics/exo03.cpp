#include <iostream>
using namespace std;


// int main()
// {
//  cout << "Пожалуйста, введите ваше имя адресата (затем нажмите 'enter'):\n";
//  string first_name; // first_name — это переменная типа string (строка)
//  cin >> first_name; // считываем символы в переменную first_name
//  cout << "Привет, " << first_name << "!\n";
// /*
//  Символ '\n' используется для переноса на новую строку
//  Я об этом не говорил на занятиях.
//  Попробуй например выполнить данную строку:
//  cout << "Папа\nи\nмама\nвернулись домой" << endl;


//  ЕСЛИ У ТЕБЯ РУССКИЙ ТЕКСТ НЕ ОТОБРАЖАЕТСЯ, ПИШИ НА АНГЛИЙСКОМ

// */
//  return 0;
// }
int main(){
    string first_name, friend_name; // Sender's and receivers names
    char friend_sex = 0; // Receiver's sex
    int friend_age = 0; // Receige age


    cout << "Enter your name : ";
    cin >> first_name;

    


    cout << "________________________\n";

    cout << "Good morning " <<  first_name <<"!\n";

    // char name = 0;
    // cin >> name;

    // if (name == 'M'){
    //     cout << "Male" << endl;
    // }else cout << "Female" << endl;
    return 0;
}