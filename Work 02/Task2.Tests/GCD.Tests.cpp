#include "pch.h"
#include "../Task2/GCD.h"
TEST(RecursiveGCDTest, GCD36and18)
{
	ASSERT_EQ(RecursiveGCD(36, 18), 18);
}
TEST(RecursiveGCDTest, GCD36and11)
{
	ASSERT_EQ(RecursiveGCD(36, 11), 1);
}
TEST(RecursiveGCDTest, GCD1200and36)
{
	ASSERT_EQ(RecursiveGCD(1200, 36), 12);
}
TEST(RecursiveGCDTest, GCD36and1200)
{
	ASSERT_EQ(RecursiveGCD(36, 1200), 12);
}