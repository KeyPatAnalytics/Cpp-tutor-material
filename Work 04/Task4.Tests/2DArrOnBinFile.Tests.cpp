#include "pch.h"
#include "../Task4/2DArrOnBinFile.cpp"
#include <fstream>


TEST(TwoDArrOnBinFile, TestWrite2DArrToBinFile) {
	// Имя файла
	const char* fileName = "data.bin";

	// Исходный двумерный массив
	int arr1[5][3] = { {1,2,3},{4,5,6},{7,8,9}, {10, 11, 12},{0,45,67} };

	// Запись массива в бинарный файл
	writeOnBin(fileName, arr1);

	// Чтение данных из бинарного файла в массив
	// Можем тоже сделать двухмерный массив вместо одномерного
	int readArr[15]; 
	ifstream inputFile(fileName, ios::binary);
	if (!inputFile.is_open()) {
		std::cout << "Error : Unable to open the file";
	}
	else {
		// Чтение данных из файла в одномерный массив
		inputFile.read(reinterpret_cast<char*>(readArr), sizeof(arr1));

		// Сравнение каждого элемента массивов
		for (int i = 0; i < 15; ++i) {
			// Сравнение элементов исходного массива
			// с элементами одномерного массива
			ASSERT_EQ(arr1[i / 3][i % 3], readArr[i]);
		}
	}

/* ТАКОЙ ПОДХОД НЕ СРАБОТАЛО, ИЗ ЗА ТОГО ЧТО БИНАРНЫЙ ФОРМАТ ЗАПИСИ
* const char* strArr = "1,2,3,4,5,6,7,8,9,10,11,12,0,45,67";
* // Размер файла
	inputFile.seekg(0, std::ios::end);
	std::streampos fileSize = inputFile.tellg();
	inputFile.seekg(0, std::ios::beg);
	// Выделение памяти
	char* binaryData = new char[static_cast<std::size_t>(fileSize)];
	// Записываем данные в виде строки
	inputFile.read(binaryData, fileSize);

	ASSERT_STREQ(strArr, binaryData);

*/
}



TEST(readFromBinaryFile, TestRead2DArrFromBinFile) {
	const char* fileName = "data.bin";
	int rows = 5, columns = 3;
	int newArr[5][3] = { {1,2,3},{4,5,6},{7,8,9}, {10, 11, 12},{0,45,67} };

	int** binaryData = readOnBinFile(fileName, rows, columns);
	if (binaryData != nullptr) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				EXPECT_EQ(newArr[i][j], binaryData[i][j]);
			}
		}
		delete[] binaryData;
	}
};
