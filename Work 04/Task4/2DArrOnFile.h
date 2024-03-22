#pragma once
#include "Task4Api.hpp"
#include <cstddef>

template <size_t rows, size_t columns>
TASK4_API void write2DArrInFile(const char* fileName, const int(&arr)[rows][columns]);
TASK4_API int** read2DArrFromFile(const char* fileName, int& nrows, int& ncolumns);