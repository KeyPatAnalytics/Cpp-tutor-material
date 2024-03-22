#include "pch.h"
#include "../Task07/Task7.cpp"

// TEST for SecantMethod
TEST(SecantMethodTest, ExampleFunction) {
    EXPECT_NEAR(SecantMethod(Parabol, 1.0, 3.0, 1e-6), 2.0, 1e-6);
};

// TEST for CountZeros with three-dimensional array
TEST(CountZerosTest, ThreeDimArray) {
    const int dim1 = 2;
    const int dim2 = 3;
    const int dim3 = 3;

    double threeDimArray[dim1][dim2][dim3] = {
        {{1.0, 0.0, 3.0}, {4.0, 0.0, 6.0}, {4.0, 7.0, 0.0}},
        {{7.0, 8.0, 9.0}, {0.0, 11.0, 12.0}, {4.0, 3.0, 6.0}}
    };

    EXPECT_EQ(CountZeros(threeDimArray), 4);
};

// TEST for CountZeros with two-dimensional array
TEST(CountZerosTest, TwoDimArray) {
    const int dim1 = 2;
    const int dim2 = 3;

    int twoDimArray[dim1][dim2] = {
        {4, 0, 6},
        {7, 8, 9}
    };

    EXPECT_EQ(CountZeros(twoDimArray), 1);
};

// TEST for CountZeros with complex array
TEST(CountZerosTest, ComplexArray) {
    const int dim1 = 2;

    ComplexNumber complexArray[dim1] = {
        {0.0, 0.0},
        {1.0, 2.0}
    };

    EXPECT_EQ(CountZeros(complexArray), 1);
};
