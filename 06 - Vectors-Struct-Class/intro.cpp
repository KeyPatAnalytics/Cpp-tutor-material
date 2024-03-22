#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(65001); // Set console output to UTF-8 encoding
    SetConsoleCP(65001); // Set console input to UTF-8 encoding

    // 1. Создание вектора и добавление элементов
    vector<int> myVector;
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    // // 2. Доступ к элементам вектора
    // cout << "Элементы вектора: ";
    // for (int i = 0; i < myVector.size(); ++i) {
    //     cout << myVector[i] << " ";
    // }
    // cout << endl;

    // 4. Размер и емкость вектора
    cout << "Размер вектора: " << myVector.size() << endl;
    cout << "Емкость вектора: " << myVector.capacity() << endl;

    // 5. Изменение размера вектора
    myVector.resize(5, 50); // Увеличение размера до 5, новые элементы заполняются значением 50

  // 6. Вставка элемента в середину вектора
    myVector.insert(myVector.begin() + 2, 99);

    // 7. Удаление элемента из вектора
    myVector.erase(myVector.begin() + 1);

    // 3. Использование итератора для доступа к элементам
    cout << "Элементы вектора (через итератор): ";
    for (vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 9. Очистка вектора
    myVector.clear();

    // 8. Проверка, пуст ли вектор
    cout << "Вектор " << (myVector.empty() ? "пуст" : "не пуст") << endl;

    // vector<int> v1;
    // vector<vector<int>> v2;

    return 0;
}
