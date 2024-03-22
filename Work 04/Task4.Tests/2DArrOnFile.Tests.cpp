#include "pch.h"
#include "../Task4/2DArrOnFile.cpp"
#include <string>


TEST(ArrayToFile, TestWriteArrToFile) {
	// �������� ����� ���� �� ���������� 
	// � ������ ������� �� ����������
	const char* fileName = "data.txt";

	int arr[3][5] = { {1,2,3,1,5},{4,5,6,6,7},{7,8,9,122,768} };
	const char* strArr = "1 2 3 1 5\n4 5 6 6 7\n7 8 9 122 768\n";

	// ���������� ������ � ����
	write2DArrInFile(fileName, arr);

	//������ �� ������ ���� ������������ �������� 
	// � �������� � ������
	//const char* fileData = nullptr;

	ifstream inputFile(fileName);
	if (!inputFile.is_open()) {
		std::cout << "Error : Unable to open the file";
	}
	else {
		// ������ �����
		std::string fileContent(
			(std::istreambuf_iterator<char>(inputFile)),
			(std::istreambuf_iterator<char>()));
		const char* fileData = fileContent.c_str();

		ASSERT_STREQ(strArr, fileData);
		//delete[] fileData;
	}
};


TEST(readFromFile, TestRead2DArrFromFile) {
	const char* fileName = "data.txt";
	int rows = 3, columns = 5;
	int arr[3][5] = { {1,2,3,1,5},{4,5,6,6,7},{7,8,9,122,768} };

	int** binaryData = read2DArrFromFile(fileName, rows, columns);
	if (binaryData != nullptr) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				EXPECT_EQ(arr[i][j], binaryData[i][j]);
			}
		}
		delete[] binaryData;
	}
};

