#include "gtest/gtest.h"
#include "Lesson2.h"

namespace
{
	//---------------1-----------------
	TEST(Lesson2Tests, ex_1)
	{
		int result = L2_exec_1(158);
		ASSERT_EQ(10011110, result);
	}

	//---------------2-----------------
	TEST(Lesson2Tests, ex_2a)
	{
		int result = L2_exec_2a(9, 3);
		ASSERT_EQ(729, result);
	}

	TEST(Lesson2Tests, ex_2b)
	{
		int result = L2_exec_2b(2, 5);
		ASSERT_EQ(32, result);
	}

	TEST(Lesson2Tests, ex_2c)
	{
		int result = L2_exec_2c(5, 4);
		ASSERT_EQ(625, result);
	}

	//---------------3-----------------
}