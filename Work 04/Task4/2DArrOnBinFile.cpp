#include "pch.h"
#include "2DArrOnBinFile.h"
#include <iostream>
#include <fstream>

using namespace std;
template <size_t nrows, size_t ncolumns >
void writeOnBin(const char* fileName, int(&arr)[nrows][ncolumns]) {
	ofstream coutFile(fileName, ios_base::binary);
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncolumns; j++) {
			coutFile.write(reinterpret_cast<const char*>(&arr[i][j]), sizeof(int));
		}
	}
	coutFile.close();
}
int** readOnBinFile(const char* fileName, int& rows, int& columns) {

	ifstream inputFile(fileName, ios::binary);

	if (!inputFile.is_open()) {
		cerr << "Error: Unable to open the file." << endl;
		return nullptr;
	}
	inputFile.seekg(0);

	int** arr1 = new int* [rows];
	for (int i = 0; i < rows; i++) {
		arr1[i] = new int[columns];
	}
	int number;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			inputFile.read(reinterpret_cast<char*>(&number), sizeof(int));
			arr1[i][j] = number;
		}

	}

	inputFile.close();
	return arr1;
}
