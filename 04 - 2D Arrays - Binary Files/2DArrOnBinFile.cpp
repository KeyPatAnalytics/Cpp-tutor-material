#include <iostream>
#include <fstream>
using namespace std;
template <size_t nrows, size_t ncols >
void writeToBinaryFile(const char* fileName, int(&arr)[nrows][ncols]) {
	ofstream coutFile(fileName, ios_base::binary);
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			coutFile.write(reinterpret_cast<const char*>(&arr[i][j]), sizeof(int));
		}
	}
	coutFile.close();
}

int** readFromBinaryFile(const char* fileName, int& rows, int& cols) {
	ifstream inputFile(fileName, ios::binary);
	inputFile.seekg(0); // Перемещение к началу файла перед чтением

	if (!inputFile.is_open()) {
		cerr << "Error: Unable to open the file." << endl;
		return nullptr;
	}

	int** arr1 = new int* [rows];
	for (int i = 0; i < rows; i++) {
		arr1[i] = new int[cols];
	}

	int number;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			inputFile.read(reinterpret_cast<char*>(&number), sizeof(int));
			arr1[i][j] = number;
		}
	}
	inputFile.close();
	return arr1;
}

int main() {
	const char* fileName = "text.bin";
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	writeToBinaryFile(fileName, arr);
	int rows = 3;
	int cols = 3;
	int** arr1 = readFromBinaryFile(fileName, rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr1[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < rows; i++) {
		delete arr1[i];
	}
	delete arr1;

	return 0;
}