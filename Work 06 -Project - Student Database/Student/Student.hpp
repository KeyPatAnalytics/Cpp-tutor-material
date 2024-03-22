// ���� Student.hpp
#pragma once
#include "StructsApi.hpp"
struct Student
{
	// ������� ��������
	wchar_t Name[30];
	// ����� ������
	int GroupNumber;
	// ������������ (��������������� ������ �� ��������� � ������)
	int Marks[5];
};
STRUCTS_API int StrLength(const char* str); // C string length

STRUCTS_API char* StrFromFile(const char* fileName); // JSON to C String (������ 1)
STRUCTS_API int CountOfSructs(const char* str); // ������� �������� (���������) � �������� �����
STRUCTS_API wchar_t* StrToWideStr(const char* str); // ������� ���� 
STRUCTS_API wchar_t* SkipUnnecessarySymbols(wchar_t* wstr);

STRUCTS_API Student* ArrayOfStudents(const char* str, int& count); // (������ 2)

STRUCTS_API wchar_t* ArrayToString(const Student* students, int count); // (������ 3)

STRUCTS_API void SortStudentsByName(Student* students, int count);// (������ 4)

STRUCTS_API Student* FindStudentsWithGoodMarks(const Student* students, int count, int& resultCount); // (������ 5)

