#include <iostream>
#include <vector>
#include "windows.h"

using namespace std;

// 1. Определение структуры Student
struct Student {
    string name;
    int id;
    double gpa;
};

// 2. Определение класса StudentDatabase
class StudentDatabase {
private:
    vector<Student> students;

public:
    // Функция для добавления нового студента
    void addStudent(const Student& s) {
        students.push_back(s);
    }

    // Функция для вывода информации о всех студентах
    void displayStudents() {
        cout << "Список студентов:\n";
        for (const auto& student : students) {
            cout << "Имя: " << student.name << ", Номер: " << student.id << ", GPA: " << student.gpa << endl;
        }
    }

    // Функция для поиска студента по номеру
    Student findStudentById(int studentId) {
        for (const auto& student : students) {
            if (student.id == studentId) {
                return student;
            }
        }
        // Если студент не найден, вернуть пустой объект Student
        return Student{"", -1, -1.0};
    }
};




int main() {

    int numberOfStudents;

    numberOfStudents = 9;

    Student patatchona;
    patatchona.name = "Patatchona";
    patatchona.id = 12434;
    patatchona.gpa = 4.3;



    // 3. Реализация основных функций
    StudentDatabase database;

    // Добавление студентов
    database.addStudent({"Alice", 101, 3.8});
    database.addStudent({"Bob", 102, 3.5});
    database.addStudent({"Charlie", 103, 4.0});

    // Вывод информации о студентах
    database.displayStudents();

    // 4. Тестирование поиска студента по номеру
    int searchId;
    cout << "Введите номер студента для поиска: ";
    cin >> searchId;

    Student foundStudent = database.findStudentById(searchId);
    if (foundStudent.id != -1) {
        cout << "Студент найден: " << foundStudent.name << ", GPA: " << foundStudent.gpa << endl;
    } else {
        cout << "Студент с таким номером не найден." << endl;
    }


    cout << patatchona.name << " has a gpa of " 
        <<patatchona.gpa << " and an ID = "
        << patatchona.id << endl;

    return 0;
}
