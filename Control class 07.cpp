#include <iostream>
#include <cmath>
#include <cstddef>

// Структура для комплексных чисел
struct ComplexNumber {
    double real;
    double imaginary;
};

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
double ExampleFunction(double x) {
    return x * x - 4;
}

// Функция подсчета нулевых элементов в трехмерном массиве вещественных чисел
template<size_t dim1, size_t dim2, size_t dim3>
int CountZeros(double (&array)[dim1][dim2][dim3]) {
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
int CountZeros(int (&array)[dim1][dim2]) {
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
int CountZeros(ComplexNumber (&array)[size]) {
    int zeroCount = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i].real == 0.0 && array[i].imaginary == 0.0) {
            zeroCount++;
        }
    }
    return zeroCount;
}

int main() {
    // Пример использования метода секущих для уравнения x^2 - 4 = 0
    double root = SecantMethod(ExampleFunction, 1.0, 3.0, 1e-6);
    std::cout << "Root of x^2 - 4 = 0: " << root << std::endl;

    // Пример использования функций подсчета нулевых элементов
    const int dim1 = 2;
    const int dim2 = 3;
    const int dim3 = 3;

    double threeDimArray[dim1][dim2][dim3] = {
        {{1.0, 0.0, 3.0}, {4.0, 0.0, 6.0}, {4.0, 7.0, 0.0}},
        {{7.0, 8.0, 9.0}, {0.0, 11.0, 12.0}, {4.0, 3.0, 6.0}}
    };
    int zerosInThreeDimArray = CountZeros(threeDimArray);
    std::cout << "Zeros in three-dimensional array: " << zerosInThreeDimArray << std::endl;

    int twoDimArray[dim1][dim2] = {
        {4, 0, 6},
        {7, 8, 9}
    };

    int zerosInTwoDimArray = CountZeros(twoDimArray);
    std::cout << "Zeros in two-dimensional array: " << zerosInTwoDimArray << std::endl;

    ComplexNumber complexArray[dim1] = {
        {0.0, 0.0},
        {1.0, 2.0}
    };
    int zerosInComplexArray = CountZeros(complexArray);
    std::cout << "Zeros in complex array: " << zerosInComplexArray << std::endl;

    return 0;
}
