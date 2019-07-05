#include "gtest/gtest.h"
#include "Lesson1.h"

namespace
{
	//---------------1-----------------
	TEST(Lesson1Tests, ex_1_Positive)
	{
		double index = exec_1(1.80, 60);
		EXPECT_NEAR(18.51, index, 0.01);
	}

	//---------------2-----------------
	TEST(Lesson1Tests, ex_2_Positive)
	{
		double rates[3] = { 15.6, 12, 0 };
		roots result = exec_2(rates);
		EXPECT_NEAR(-0.769, result.r1, 0.01);
		EXPECT_NEAR(0, result.r2, 0.01);
	}

	TEST(Lesson1Tests, ex_2_NegativeD)
	{
		double rates[3] = { 5, 2, 20 };
		roots result = exec_2(rates);
		EXPECT_NEAR(0, result.r1, 0.01);
		EXPECT_NEAR(0, result.r2, 0.01);
	}

	//---------------3-----------------
	TEST(Lesson1Tests, ex_3_1)
	{
		char* result = exec_3(1);
		ASSERT_STREQ("1 год", result);
	}

	TEST(Lesson1Tests, ex_3_2)
	{
		char* result = exec_3(2);
		ASSERT_STREQ("2 года", result);
	}

	TEST(Lesson1Tests, ex_3_5)
	{
		char* result = exec_3(5);
		ASSERT_STREQ("5 лет", result);
	}

	TEST(Lesson1Tests, ex_3_30)
	{
		char* result = exec_3(30);
		ASSERT_STREQ("30 лет", result);
	}

	TEST(Lesson1Tests, ex_3_121)
	{
		char* result = exec_3(121);
		ASSERT_STREQ("121 год", result);
	}

	//------------4-----------------
	TEST(Lesson1Tests, ex_4_13_86)
	{
		point p1, p2;
		p1.x = 1; p1.y = 3;
		p2.x = 8; p2.y = 6;

		boolean result = exec_4(p1, p2);
		ASSERT_EQ(_true, result);
	}

	TEST(Lesson1Tests, ex_4_27_16)
	{
		point p1, p2;
		p1.x = 2; p1.y = 7;
		p2.x = 1; p2.y = 6;

		boolean result = exec_4(p1, p2);
		ASSERT_EQ(_false, result);
	}

	TEST(Lesson1Tests, ex_5)
	{
		int expected[] = { 0, 1, 5, 6, 25, 76, 376, 625, 9376 };
		int* result = exec_5(10000);

		for (int i = 0; i < sizeof(expected) / sizeof(int); i++)
		{
			ASSERT_EQ(expected[i], result[i]);
		}
	}
}




