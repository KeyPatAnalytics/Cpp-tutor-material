#include "pch.h"
#include "Var18MinSumIndiag2DArr.h"

template <size_t size>
int MinSumInDiag2DArr(const int(&arr)[size][size]) {
	int sum1 = arr[size - 1][0];
	int sum2;
	for (int m = size - 1; m > 0; m--) {
		sum2 = 0;
		for (int i = m, j = 0; i < size && j < size; i++, j++) {
			sum2 += arr[i][j];
		}
		if (sum2 < sum1)
		{
			sum1 = sum2;
		}
	}
	for (int m = 1; m < size; m++) {
		sum2 = 0;
		for (int j = m, i = 0; i < size && j < size; i++, j++) {
			sum2 += arr[i][j];
		}
		if (sum2 < sum1)
		{
			sum1 = sum2;
		}
	}
	return sum1;
}