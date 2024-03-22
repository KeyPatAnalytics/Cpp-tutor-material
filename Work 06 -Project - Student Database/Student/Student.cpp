// ���� Student.cpp
#include "pch.h"
#include "Student.hpp"


// ������� ���������� ����� ������
int StrLength(const char* str)
{
	const char* begin = str;
	while (*str++)
		;
	return (int)(str - 1 - begin);
}



// ������� ���������� ������, �������� �� ���������� �����
char* StrFromFile(const char* fileName)
{
	// fstream __> C++
	// ifstream(filename)
	// 
	// ��������� �� ���� (��������� ���������� � ����� stdio.h)
	FILE* ptrFile;
	ptrFile = fopen(fileName, "r+");// �������� ����� ��� �����
	if (ptrFile == nullptr)
		return nullptr;

	// ����������� ������� ����� � ������
	fseek(ptrFile, 0, SEEK_END); // ����������� ������� ����� � ����� �����
	
	long fileSize = ftell(ptrFile); // ���������� ������� �������
	rewind(ptrFile); // �������-� ������� � ������ ����� ��� ������������ ������ ������
	char* buffer = new char[fileSize + 1] {};

	// ���� ������ �� �����
	// 1 byte = 8 bits (������ �������� � byte)
	// 1 ���� = 8�����
	fread(buffer, 1, fileSize, ptrFile); // ���������� ��������� ��������
	fclose(ptrFile); // �������� �����
	return buffer;
}


// ������� ���������� ���������� �������� � JSON-������
int CountOfSructs(const char* str)
{
	int count = 0;
	while (*str)
	{
		if (*str++ == '{')
			++count;
	}
	return count;
}

// ����������� ������ �������� ���� char � ������ �������� ���� wchar_t
wchar_t* StrToWideStr(const char* str)
{
	size_t length = StrLength(str); // ����� ������ str (��� ������� '\0')
	// ���������� ���������������� ��������
	size_t converted = 0;
	wchar_t* wstr = new wchar_t[length + 1];

	// �������������� ������ str � ������ wstr (���� stdlib.h).
	converted = mbstowcs(wstr, str, length + 1);
	if (converted != length)
		return nullptr;
	// ��� ����� ��� ������������� ������ str � ������ wstr (���� stringapiset.h):
	//MultiByteToWideChar(CP_ACP, MB_USEGLYPHCHARS, str, length, wstr, length);
	// ����� CP_ACP - ������� ��������, MB_USEGLYPHCHARS - �����,
	// length - ���������� ������������� ��������.
	return wstr;
}

// ������� ���������� ��������� �� ������ � ������ wstr ����� ������� ������� L':'.
// ���� ������� L':' � ������ ���, ���������� ��������� �� ����� ������ wstr (�� L'\0').
wchar_t* SkipUnnecessarySymbols(wchar_t* wstr)
{
	int indexOfColon = 0;
	// ���������� "� ������" ���� �������� �� ������� ������� L':';
	// ��������� ���������� �������� ��������� � indexOfColon.
	swscanf(wstr, L"%*[^:]%n", &indexOfColon); // colon � ������ ���������
	if (*(wstr + indexOfColon) == L':')
		++indexOfColon; // ������� ������� ':'
	return wstr + indexOfColon;
}


// ������ 2

// ������������ ���������� (count) �������� � ������ str,
// ������ � ���������� ������ ���� ��������.
Student* ArrayOfStudents(const char* str, int& count)
{
	count = CountOfSructs(str);
	if (!count)
		return nullptr;

	// �������������� ������ �������� ���� char � ������ �������� ���� wchar_t
	wchar_t* wstr = StrToWideStr(str);

	wchar_t* startwstr = wstr; // ��� ������������ delete
	// ������������ ������� �������� �� ������ �������� wstr
	Student* students = new Student[count]; // �������� ������� ��������
	for (int k = 0; k < count; ++k)
	{
		// ���������� ����������� ��������
		int distance = 0;

		wstr = SkipUnnecessarySymbols(wstr);//������� �� �������,����-�� �� ����.L':'
		swscanf(wstr, L"%*[^\"]%n", &distance); // ������� �� ������� L'\"'
		wstr += distance + 1; // ������� ������� L'\"'
		swscanf(wstr, L"%[^\"]s", &students[k].Name);//���� ������ �� ����.����.L'\"'
		
		
		wstr = SkipUnnecessarySymbols(wstr);//������� �� �������,����-�� �� ����.L':'
		distance = 0;
		swscanf(wstr, L"%*[^0-9]%n", &distance); // ������� �������� �� �����
		wstr += distance;
		swscanf(wstr, L"%d", &students[k].GroupNumber); // ���� ������ �����



		wstr = SkipUnnecessarySymbols(wstr);//������� �� �������,����-�� �� ����.L':'
		
		for (int i = 0; i < 5; ++i)
		{
			distance = 0;
			swscanf(wstr, L"%*[^0-9]%n", &distance); // ������� �������� �� �����
			wstr += distance;
			swscanf(wstr, L"%d", &(students[k].Marks[i])); // ���� ������ �����
			++wstr; // ������� ����� �����
		}
	}
	delete[] startwstr;
	return students;
}




// ������ 3

// ������� ������ � ������ ������� ��������
wchar_t* ArrayToString(const Student* students, int count)
{
	// �����������, ��� ������������ ����� ������ �� ��������� 500 ��������
	const int maxStringLength = 500;
	wchar_t* resultString = new wchar_t[maxStringLength];

	const wchar_t* line = L"+--------------------------------+--------------+-----------------+";
	swprintf(resultString, maxStringLength, L"%ls\n", line);

	swprintf(resultString + wcslen(resultString), maxStringLength - wcslen(resultString),
		L"| %-30ls | %-12ls | %-15ls |\n", L"Name", L"GroupNumber", L"Marks");

	swprintf(resultString + wcslen(resultString), maxStringLength - wcslen(resultString), L"%ls\n", line);


	for (int i = 0; i < count; ++i)
	{
		swprintf(resultString + wcslen(resultString), maxStringLength - wcslen(resultString),
			L"| %-30s | %-12d | %-2d %-2d %-2d %-2d %-2d  |\n",
			students[i].Name, students[i].GroupNumber, students[i].Marks[0], students[i].Marks[1],
			students[i].Marks[2], students[i].Marks[3], students[i].Marks[4]);
		swprintf(resultString + wcslen(resultString), maxStringLength - wcslen(resultString), L"%ls\n", line);
	}
	return resultString;
}



// ������ 4

// ������� ��������� ��� ������������� � qsort
int CompareStudents(const void* a, const void* b)
{
	return wcscmp(((Student*)a)->Name, ((Student*)b)->Name);
}

// ������� ��� �������������� ������� Students � ���������� �������
void SortStudentsByName(Student* students, int count)
{
	// �� ����� �������� ���������� ������ ��� � ���������� ��
	qsort(students, count, sizeof(Student), CompareStudents);
}



// ������ 5
// 
// ������� ������ ��������� ��� �������������������� � ������������������ ������
Student* FindStudentsWithGoodMarks(const Student* students, int count, int& resultCount)
{
	// �����������, ��� ������������ ���������� ��������� ��� ����. � �����. ������ - count
	Student* resultStudents = new Student[count];
	resultCount = 0;

	for (int i = 0; i < count; ++i)
	{
		bool hasBadMarks = false;
		for (int j = 0; j < 5; ++j)
		{
			if (students[i].Marks[j] <= 3)
			{
				hasBadMarks = true;
				break;
			}
		}

		if (!hasBadMarks)
		{
			resultStudents[resultCount] = students[i];
			++resultCount;
		}
	}

	if (resultCount == 0)
	{
		delete[] resultStudents;
		return nullptr;
	}

	return resultStudents;
}

