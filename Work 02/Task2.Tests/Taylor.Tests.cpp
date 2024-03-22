#include "pch.h"
#include "../Task2/Taylor.h"
TEST(TaylorTest, Taylor1)
{
	EXPECT_NEAR(Taylor(0, 1e-6).first, 1.571,0.001);
}