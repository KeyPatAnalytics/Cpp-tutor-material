#include "pch.h"

#include "../Student/Student.hpp"



TEST(StudentStructTests, StrLengthTest)
{
	ASSERT_EQ(0, StrLength(""));
	ASSERT_EQ(5, StrLength("12345"));
	ASSERT_EQ(25, StrLength("aaa 12345\tbbbbb 67.\nAAA!\n"));
}

TEST(StudentStructTests, StrFromFileTest)
{
	const char* str = "[\n\t{\n\t\t\"Name\": \"Petrov\",\n\t\t\"GroupNumber\": 1234,\n\t\t\"Marks\": [3,4,3,4,4]\n\t},\n\t{\n\t\t\"Name\": \"Ivanov\",\n\t\t\"GroupNumber\": 5678,\n\t\t\"Marks\": [5,4,5,4,3]\n\t}\n]";
	char* result = StrFromFile("data.json");
	ASSERT_STREQ(str, result);
	delete[] result;
}
TEST(StudentStructTests, CountOfSructsTest)
{
	ASSERT_EQ(0, CountOfSructs(""));
	ASSERT_EQ(0, CountOfSructs("fbwi iwdui qiqwh uiw [] wefe."));
	const char* str = "[\n {\n \"Name\":\"Petrov\",\n \"GroupNumber\":1234,\n \"Marks\":[3,4,3,4,4]\n },\n {\n \"Name\":\"Ivanov\",\n \"GroupNumber\":5678,\n \"Marks\":[5,4,5,4,3]\n}\n]";
ASSERT_EQ(2, CountOfSructs(str));
}
TEST(StudentStructTests, StrToWStrTest)
{
	const char* str = "[\n {\n \"Name\":\"Petrov\",\n \"GroupNumber\":1234,\n \"Marks\":[3,4,3,4,4]\n },\n {\n \"Name\":\"Ivanov\",\n \"GroupNumber\":5678,\n \"Marks\":[5,4,5,4,3]\n }\n]";
const wchar_t* wstr = L"[\n {\n \"Name\":\"Petrov\",\n \"GroupNumber\":1234,\n \"Marks\":[3,4,3,4,4]\n },\n {\n \"Name\":\"Ivanov\",\n \"GroupNumber\":5678,\n \"Marks\":[5,4,5,4,3]\n }\n]";
wchar_t* wresult = StrToWideStr(str);
	ASSERT_STREQ(wstr, wresult);
	delete[] wresult;
}
TEST(StudentStructTests, StrToWStrWithRussianSymbolsTest)
{
	setlocale(LC_ALL, "Russian");
	const char* str = "[\n {\n \"Name\":\"Петров\",\n \"GroupNumber\":1234,\n \"Marks\":[3,4,3,4,4]\n },\n {\n \"Name\":\"Иванов\",\n \"GroupNumber\":5678,\n \"Marks\":[5,4,5,4,3]\n }\n]";
const wchar_t* wstr = L"[\n {\n \"Name\":\"Петров\",\n \"GroupNumber\":1234,\n \"Marks\":[3,4,3,4,4]\n },\n {\n \"Name\":\"Иванов\",\n \"GroupNumber\":5678,\n \"Marks\":[5,4,5,4,3]\n }\n]";
wchar_t* wresult = StrToWideStr(str);
	ASSERT_STREQ(wstr, wresult);
	delete[] wresult;
}
TEST(StudentStructTests, SkipUnnecessarySymbolsTest)
{
	wchar_t wstr[] = { L"1 2 3 4 5 6 : Programming : 123" };
	const wchar_t* wstr1 = L" Programming : 123";
	ASSERT_STREQ(wstr1, SkipUnnecessarySymbols(wstr));
}
TEST(StudentStructTests, SkipUnnecessarySymbolsWithoutColon)
{
	wchar_t wstr[] = { L"1 2 3 4 5 6 Programming 123" };
	ASSERT_STREQ(L"", SkipUnnecessarySymbols(wstr));
}
TEST(StudentStructTests, SkipUnnecessarySymbolsInEmptyStrTest)
{
	wchar_t wstr[] = { L"" };
	ASSERT_STREQ(L"", SkipUnnecessarySymbols(wstr));
}
TEST(StudentStructTests, ArrayOfStudentsTest)
{
	const char* str = "[\n {\n \"Name\":\"Petrov\",\n \"GroupNumber\":1234,\n \"Marks\":[3,4,3,4,4]\n },\n {\n \"Name\":\"Ivanov\",\n \"GroupNumber\":5678,\n \"Marks\":[5,4,5,4,3]\n }\n]";
int count = 0;
	Student* students = ArrayOfStudents(str, count);
	ASSERT_EQ(2, count);
	ASSERT_STREQ(L"Petrov", students[0].Name);
	ASSERT_EQ(1234, students[0].GroupNumber);
	short arr1[] = { 3, 4, 3, 4, 4 };
	for (int i = 0; i < 5; ++i)
		ASSERT_EQ(arr1[i], students[0].Marks[i]);
	ASSERT_STREQ(L"Ivanov", students[1].Name);
	ASSERT_EQ(5678, students[1].GroupNumber);
	short arr2[] = { 5, 4, 5, 4, 3 };
	for (int i = 0; i < 5; ++i)
		ASSERT_EQ(arr2[i], students[1].Marks[i]);
	delete[] students;
}
TEST(StudentStructTests, ArrayOfStudentsFromStrWithoutWhitespasesTest)
{
	const char* str = "[{\"Name\":\"Petrov\",\"GroupNumber\":1234,\"Marks\":[3,4,3,4,4]},{\"Name\":\"Ivanov\",\"GroupNumber\":5678,\"Marks\":[5,4,5,4,3]}]";
	int count = 0;
	Student* students = ArrayOfStudents(str, count);
	ASSERT_EQ(2, count);
	ASSERT_STREQ(L"Petrov", students[0].Name);
	ASSERT_EQ(1234, students[0].GroupNumber);
	short arr1[] = { 3, 4, 3, 4, 4 };
	for (int i = 0; i < 5; ++i)
		ASSERT_EQ(arr1[i], students[0].Marks[i]);
	ASSERT_STREQ(L"Ivanov", students[1].Name);
	ASSERT_EQ(5678, students[1].GroupNumber);
	short arr2[] = { 5, 4, 5, 4, 3 };
	for (int i = 0; i < 5; ++i)
		ASSERT_EQ(arr2[i], students[1].Marks[i]);
	delete[] students;
}
TEST(StudentStructTests, ArrayOfStudentsFromStrWithAnyQuantityOfWhitespasesTest)
{
	const char* str = "[\n {\n \"Name\": \"Petrov\",\n \"GroupNumber\": 1234,\n \"Marks\": [ 3, 4, 3, 4, 4]\n },\n {\n \"Name\": \"Ivanov\",\n \"GroupNumber\": 5678,\n \"Marks\": [ 5, 4,	5, 4, 3]\n }\n]";
int count = 0;
	Student* students = ArrayOfStudents(str, count);
	ASSERT_EQ(2, count);
	ASSERT_STREQ(L"Petrov", students[0].Name);
	ASSERT_EQ(1234, students[0].GroupNumber);
	short arr1[] = { 3, 4, 3, 4, 4 };
	for (int i = 0; i < 5; ++i)
		ASSERT_EQ(arr1[i], students[0].Marks[i]);
	ASSERT_STREQ(L"Ivanov", students[1].Name);
	ASSERT_EQ(5678, students[1].GroupNumber);
	short arr2[] = { 5, 4, 5, 4, 3 };
	for (int i = 0; i < 5; ++i)
		ASSERT_EQ(arr2[i], students[1].Marks[i]);
	delete[] students;
}
TEST(StudentStructTests, ArrayOfRussianStudentsTest)
{
	setlocale(LC_ALL, "Russian");
	const char* str = "[\n {\n \"Name\":\"Петров\",\n \"GroupNumber\":1234,\n \"Marks\":[3,4,3,4,4]\n },\n {\n \"Name\":\"Иванов\",\n \"GroupNumber\":5678,\n \"Marks\":[5,4,5,4,3]\n }\n]";
int count = 0;
	Student* students = ArrayOfStudents(str, count);
	ASSERT_EQ(2, count);
	ASSERT_STREQ(L"Петров", students[0].Name);
	ASSERT_EQ(1234, students[0].GroupNumber);
	short arr1[] = { 3, 4, 3, 4, 4 };
	for (int i = 0; i < 5; ++i)
		ASSERT_EQ(arr1[i], students[0].Marks[i]);
	ASSERT_STREQ(L"Иванов", students[1].Name);
	ASSERT_EQ(5678, students[1].GroupNumber);
	short arr2[] = { 5, 4, 5, 4, 3 };
	for (int i = 0; i < 5; ++i)
		ASSERT_EQ(arr2[i], students[1].Marks[i]);
	delete[] students;
}


// Вопрос 3
TEST(StudentStructTests, ArrayToStringTest)
{
	// Create an array of students
	Student students[] = {
		{L"Petrov", 1234, {3, 4, 3, 4, 4}},
		{L"Ivanov", 5678, {5, 4, 5, 4, 3}}
	};

	// Call the function to get the result string
	wchar_t* resultString = ArrayToString(students, 2);

	// Define the expected string
	const wchar_t* expected =
		L"+--------------------------------+--------------+-----------------+\n"
		L"| Name                           | GroupNumber  | Marks           |\n"
		L"+--------------------------------+--------------+-----------------+\n"
		L"| Petrov                         | 1234         | 3  4  3  4  4   |\n"
		L"+--------------------------------+--------------+-----------------+\n"
		L"| Ivanov                         | 5678         | 5  4  5  4  3   |\n"
		L"+--------------------------------+--------------+-----------------+\n";

	// Print the result and expected strings
	wprintf(L"Result:\n%ls\n", resultString);
	wprintf(L"Expected:\n%ls\n", expected);

	// Compare the result string with the expected string
	ASSERT_EQ(0, wcscmp(resultString, expected));

	// Clean up: don't forget to delete the dynamically allocated buffer
	delete[] resultString;
}


// Вопрос 4
TEST(StudentStructTests, SortStudentsByNameTest)
{
	Student students[] = {
		{L"Ivanov", 5678, {5, 4, 5, 4, 3}},
		{L"Alinova", 1234, {3, 4, 3, 4, 4}}
	};

	SortStudentsByName(students, 2);

	const wchar_t* expectedOrder = L"Alinova";
	ASSERT_EQ(0, wcscmp(students[0].Name, expectedOrder));
}



// Вопрос 5
TEST(StudentStructTests, FindStudentsWithGoodMarks)
{
	Student students[] = {
		{L"Ivanov", 5678, {5, 4, 5, 4, 5}},
		{L"Petrov", 1234, {3, 4, 3, 4, 4}}
	};

	int resultCount = 0;
	Student* result = FindStudentsWithGoodMarks(students, 2, resultCount);

	ASSERT_EQ(1, resultCount);
	ASSERT_EQ(0, wcscmp(result[0].Name, L"Ivanov"));

	delete[] result;
}


