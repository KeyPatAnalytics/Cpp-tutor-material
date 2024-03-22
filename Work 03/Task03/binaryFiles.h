#pragma once
#include "TASK3_API.hpp"

TASK3API void writeArrayToBinaryFile(const char* fileName, const int* array, int size);
TASK3API int* readArrayFromBinaryFile(const char* fileName, int& size);
