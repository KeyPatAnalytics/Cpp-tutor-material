#include "pch.h"
#include "Task7.h"

// Функция решения уравнения методом секущих
double SecantMethod(double (*f)(double), double x0, double x1, double epsilon) {
    double x2;
    do {
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
    } while (std::abs(f(x2)) > epsilon);

    return x2;
}

// Пример функции для уравнения f(x) = x^2 - 4
double Parabol(double x) {
    return x * x - 4;
}

// Функция подсчета нулевых элементов в трехмерном массиве вещественных чисел
template<size_t dim1, size_t dim2, size_t dim3>
int CountZeros(double(&array)[dim1][dim2][dim3]) {
    int zeroCount = 0;
    for (int i = 0; i < dim1; ++i) {
        for (int j = 0; j < dim2; ++j) {
            for (int k = 0; k < dim3; ++k) {
                if (array[i][j][k] == 0.0) {
                    // std::cout << "Found zero at array[" << i << ","<< j << ","<< k << "]"<< std::endl;
                    zeroCount++;
                }
            }
        }
    }
    return zeroCount;
}

// Функция подсчета нулевых элементов в двумерном массиве целых чисел
template<size_t dim1, size_t dim2>
int CountZeros(int(&array)[dim1][dim2]) {
    int zeroCount = 0;
    for (int i = 0; i < dim1; ++i) {
        for (int j = 0; j < dim2; ++j) {
            if (array[i][j] == 0) {
                zeroCount++;
            }
        }
    }
    return zeroCount;
}

// Функция подсчета нулевых элементов в одномерном массиве комплексных чисел
template <size_t size>
int CountZeros(ComplexNumber(&array)[size]) {
    int zeroCount = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i].real == 0.0 && array[i].imaginary == 0.0) {
            zeroCount++;
        }
    }
    return zeroCount;
}
