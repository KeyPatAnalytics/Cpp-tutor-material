#include<iostream>
using namespace std;


//дан массив целых чисел, написать функцию, которая вернет массив из чисел,
// которые повторяются Repet раз в порядке возрастания

int* GetNum(const int* data, unsigned size, unsigned repeat, unsigned& resultSize) {
    resultSize = 0;
    int index = 0;

    for (int i = 0; i < size - 1; i++) {
        int col = 1;
        for (int j = i + 1; j < size; j++) {
            if (data[i] == data[j]) {
                col++;
            }
        }
        if (col == repeat) {
            resultSize += 1;
        }
    }

    if (resultSize > 0) {
        int* data2 = new int[resultSize];
        for (int i = 0; i < size; i++) {
            int col = 1;
            for (int j = i + 1; j < size; j++) {
                if (data[i] == data[j]) {
                    col++;
                }
            }
            if (col == repeat) {
                data2[index] = data[i];
                index++;
            }
        }

        // Sort the array using bubble sort
        for (int q = 0; q < resultSize; q++) {
            for (int w = q + 1; w < resultSize; w++) {
                if (data2[q] > data2[w])
                    swap(data2[q], data2[w]);
            }
        }
        return data2;
    }
    else {
        return nullptr;
    }
}

	
int main() {
	const int a[] = { 1, 3, 3, 2, 2, 1, 4 };

	//Мы передаем ResultSize по адрессу, поэтому его обязательно объявлять
	unsigned int ResultSize = 0;
	int repeat = 2;
	
	// GetNum возвращает указатель на массив поэтому `cout << GetNum(a, 7, 2, 0)` не будет работать
	
	int* resultData = GetNum(a, 7, 2, ResultSize);

	if (ResultSize > 0) {
		cout << "List of numbers repeating "<< repeat << " times:";
		for (int i = 0; i < ResultSize; i++) {
			cout << " " << resultData[i];
		}
		cout << endl;
	}
	else {
		cout << "There are no repeating numbers in the given array !" << endl;
	}

	delete[] resultData;

	return 0;
}


	