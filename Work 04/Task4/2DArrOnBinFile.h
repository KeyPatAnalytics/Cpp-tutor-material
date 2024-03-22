#pragma once
#include "Task4Api.hpp"
#include <cstddef>

template <size_t nrows, size_t ncolumns>
TASK4_API void writeOnBin(const char* fileName, int(&arr)[nrows][ncolumns]);
TASK4_API int** readOnBinFile(const char* fileName, int& rows, int& columns);