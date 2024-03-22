// Файл Student.cpp
#include "pch.h"
#include "Student.hpp"


// Функция возвращает длину строки
int StrLength(const char* str)
{
	const char* begin = str;
	while (*str++)
		;
	return (int)(str - 1 - begin);
}



// Функция возвращает строку, введённую из текстового файла
char* StrFromFile(const char* fileName)
{
	// fstream __> C++
	// ifstream(filename)
	// 
	// Указатель на файл (структура определена в файле stdio.h)
	FILE* ptrFile;
	ptrFile = fopen(fileName, "r+");// открытие файла для ввода
	if (ptrFile == nullptr)
		return nullptr;

	// Определение размера файла в байтах
	fseek(ptrFile, 0, SEEK_END); // перемещение маркера ввода в конец файла
	
	long fileSize = ftell(ptrFile); // возвращает позицию маркера
	rewind(ptrFile); // перемещ-е маркера в начало файла для последующего чтения данных
	char* buffer = new char[fileSize + 1] {};

	// Ввод строки из файла
	// 1 byte = 8 bits (Второй параметр в byte)
	// 1 байт = 8битов
	fread(buffer, 1, fileSize, ptrFile); // количество считанных символов
	fclose(ptrFile); // закрытие файла
	return buffer;
}


// Функция возвращает количество структур в JSON-строке
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

// Преобразует строку символов типа char в строку символов типа wchar_t
wchar_t* StrToWideStr(const char* str)
{
	size_t length = StrLength(str); // длина строки str (без символа '\0')
	// Количество конвертированных символов
	size_t converted = 0;
	wchar_t* wstr = new wchar_t[length + 1];

	// Преобразование строки str в строку wstr (файл stdlib.h).
	converted = mbstowcs(wstr, str, length + 1);
	if (converted != length)
		return nullptr;
	// Ещё можно так преобразовать строку str в строку wstr (файл stringapiset.h):
	//MultiByteToWideChar(CP_ACP, MB_USEGLYPHCHARS, str, length, wstr, length);
	// Здесь CP_ACP - кодовая страница, MB_USEGLYPHCHARS - флаги,
	// length - количество преобразуемых символов.
	return wstr;
}

// Функция возвращает указатель на символ в строке wstr после первого символа L':'.
// Если символа L':' в строке нет, возвращает указатель на конец строки wstr (на L'\0').
wchar_t* SkipUnnecessarySymbols(wchar_t* wstr)
{
	int indexOfColon = 0;
	// Считывание "в никуда" всех символов до первого символа L':';
	// считанное количество символов заносится в indexOfColon.
	swscanf(wstr, L"%*[^:]%n", &indexOfColon); // colon – символ двоеточия
	if (*(wstr + indexOfColon) == L':')
		++indexOfColon; // пропуск символа ':'
	return wstr + indexOfColon;
}


// Вопрос 2

// Подсчитывает количество (count) структур в строке str,
// создаёт и возвращает массив этих структур.
Student* ArrayOfStudents(const char* str, int& count)
{
	count = CountOfSructs(str);
	if (!count)
		return nullptr;

	// Преобразование строки символов типа char в строку символов типа wchar_t
	wchar_t* wstr = StrToWideStr(str);

	wchar_t* startwstr = wstr; // Для последующего delete
	// Формирование массива структур из строки символов wstr
	Student* students = new Student[count]; // создание массива структур
	for (int k = 0; k < count; ++k)
	{
		// Количество пропущенных символов
		int distance = 0;

		wstr = SkipUnnecessarySymbols(wstr);//пропуск до символа,след-го за симв.L':'
		swscanf(wstr, L"%*[^\"]%n", &distance); // пропуск до символа L'\"'
		wstr += distance + 1; // пропуск символа L'\"'
		swscanf(wstr, L"%[^\"]s", &students[k].Name);//ввод строки до след.симв.L'\"'
		
		
		wstr = SkipUnnecessarySymbols(wstr);//пропуск до символа,след-го за симв.L':'
		distance = 0;
		swscanf(wstr, L"%*[^0-9]%n", &distance); // пропуск символов до цифры
		wstr += distance;
		swscanf(wstr, L"%d", &students[k].GroupNumber); // ввод целого числа



		wstr = SkipUnnecessarySymbols(wstr);//пропуск до символа,след-го за симв.L':'
		
		for (int i = 0; i < 5; ++i)
		{
			distance = 0;
			swscanf(wstr, L"%*[^0-9]%n", &distance); // пропуск символов до цифры
			wstr += distance;
			swscanf(wstr, L"%d", &(students[k].Marks[i])); // ввод целого числа
			++wstr; // пропуск одной цифры
		}
	}
	delete[] startwstr;
	return students;
}




// Вопрос 3

// Функция вывода в строку массива структур
wchar_t* ArrayToString(const Student* students, int count)
{
	// Предположим, что максимальная длина строки не превышает 500 символов
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



// Вопрос 4

// Функция сравнения для использования в qsort
int CompareStudents(const void* a, const void* b)
{
	return wcscmp(((Student*)a)->Name, ((Student*)b)->Name);
}

// Функция для упорядочивания массива Students в алфавитном порядке
void SortStudentsByName(Student* students, int count)
{
	// Мы можем написать собсвенную фунцию как в предыдущем дз
	qsort(students, count, sizeof(Student), CompareStudents);
}



// Вопрос 5
// 
// Функция поиска студентов без неудовлетворительных и удовлетворительных оценок
Student* FindStudentsWithGoodMarks(const Student* students, int count, int& resultCount)
{
	// Предположим, что максимальное количество студентов без неуд. и удовл. оценок - count
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

