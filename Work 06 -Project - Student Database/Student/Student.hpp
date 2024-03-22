// Файл Student.hpp
#pragma once
#include "StructsApi.hpp"
struct Student
{
	// Фамилия студента
	wchar_t Name[30];
	// Номер группы
	int GroupNumber;
	// Успеваемость (экзаменационные оценки по предметам в сессию)
	int Marks[5];
};
STRUCTS_API int StrLength(const char* str); // C string length

STRUCTS_API char* StrFromFile(const char* fileName); // JSON to C String (вопрос 1)
STRUCTS_API int CountOfSructs(const char* str); // Сколько структур (студентов) в исходном файле
STRUCTS_API wchar_t* StrToWideStr(const char* str); // Перевод типа 
STRUCTS_API wchar_t* SkipUnnecessarySymbols(wchar_t* wstr);

STRUCTS_API Student* ArrayOfStudents(const char* str, int& count); // (Вопрос 2)

STRUCTS_API wchar_t* ArrayToString(const Student* students, int count); // (Вопрос 3)

STRUCTS_API void SortStudentsByName(Student* students, int count);// (Вопрос 4)

STRUCTS_API Student* FindStudentsWithGoodMarks(const Student* students, int count, int& resultCount); // (Вопрос 5)

