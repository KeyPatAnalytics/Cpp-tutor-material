#include "pch.h"
#include "../Task4/Var18MinSumInDiag2DArr.cpp"
TEST(MinSumInDiag2DArrTests, test1)
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	ASSERT_EQ(MinSumInDiag2DArr(arr), 3);
}
TEST(MinSumInDiag2DArrTests, testOn0Arr)
{
	int arr[4][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
	ASSERT_EQ(MinSumInDiag2DArr(arr), 0);
}
TEST(MinSumInDiag2DArrTests, testOn0ArrExceptForTheMainDiag)
{
	int arr[4][4] = { {9,0,0,0},{0,8,0,0},{0,0,7,0},{0,0,0,9} };
	ASSERT_EQ(MinSumInDiag2DArr(arr), 0);
}
TEST(MinSumInDiag2DArrTests, testForTheMainDiag0)
{
	int arr[3][3] = { {0,2,3},{4,0,6},{7,8,0} };
	ASSERT_EQ(MinSumInDiag2DArr(arr), 3);
}