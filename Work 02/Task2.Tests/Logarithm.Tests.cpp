#include "pch.h"
#include "../Task2/Logarithm.h"
TEST(LogarithmTest, newlog2on0)
{
	ASSERT_EQ(find_log2(0), -2);
}
TEST(LogarithmTest, newlog2onOtr1)
{
	ASSERT_EQ(find_log2(-1), -2);
}
TEST(LogarithmTest, newlog2on1)
{
	ASSERT_EQ(find_log2(1), 0);
}
TEST(LogarithmTest, newlog2on1024)
{
	ASSERT_EQ(find_log2(1024), 10);
}
TEST(LogarithmTest, newlog2on1111)
{
	ASSERT_EQ(find_log2(1111), -1);
}
