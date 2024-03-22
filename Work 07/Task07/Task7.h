#pragma once
#include "Task7Api.hpp"
#include <iostream>
#include <cmath>
#include <cstddef>

// Структура для комплексных чисел
struct ComplexNumber {
    double real;
    double imaginary;
};

TASK7_API double SecantMethod(double (*f)(double), double x0, double x1, double epsilon);
TASK7_API double Parabol(double x);

template<size_t dim1, size_t dim2, size_t dim3>
TASK7_API int CountZeros(double(&array)[dim1][dim2][dim3]);


template<size_t dim1, size_t dim2>
TASK7_API  int CountZeros(int(&array)[dim1][dim2]);

template <size_t size>
TASK7_API int CountZeros(ComplexNumber(&array)[size]);
