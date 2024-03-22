#include "pch.h"
#include "2DArrOnFile.h"
#include <iostream>
#include <fstream>

using namespace std;
template <size_t rows, size_t columns>
void write2DArrInFile(const char* fileName, const int(&arr)[rows][columns]) {
	ofstream outFile(fileName);
	if (!outFile.is_open())  cerr << "Error: cannot open file";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns-1; j++) {
			outFile << arr[i][j] << " ";
		}
		outFile << arr[i][columns - 1]  << "\n";
	}
	outFile.close();
}

int** read2DArrFromFile(const char* fileName, int& nrows, int& ncolumns) {
	ifstream inputFile(fileName);
	if (!inputFile.is_open()) {
		cerr << "Error: Unable to open the file." << endl;
		return nullptr;
	}
	int** arr1 = new int* [nrows];
	for (int i = 0; i < nrows; ++i) {
		arr1[i] = new int[ncolumns];
	}
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncolumns; j++) {
			inputFile >> arr1[i][j];
		}
	}
	inputFile.close();
	return arr1;
}