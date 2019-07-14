#include "gtest/gtest.h"
#include "Lesson4.h"

namespace
{
	//------------Бинарный поиск---------------
	TEST(Lesson3Tests, BinarySearch_Test1)
	{
		int arr[] = { 0, 1, 54, 156, 234, 264, 346, 642,  643 };
		int SIZE = sizeof(arr) / sizeof(int);

		int index = BinarySearch(arr, SIZE, 234);

		ASSERT_EQ(4, index);
	}

	TEST(Lesson3Tests, BinarySearch_Test2)
	{
		int arr[] = { 0, 1, 54, 156, 234, 264, 346, 642,  643 };
		int SIZE = sizeof(arr) / sizeof(int);

		int index = BinarySearch(arr, SIZE, 1);

		ASSERT_EQ(1, index);
	}

	TEST(Lesson3Tests, BinarySearch_Test3)
	{
		int arr[] = { 0, 1, 54, 156, 234, 264, 346, 642,  643 };
		int SIZE = sizeof(arr) / sizeof(int);

		int index = BinarySearch(arr, SIZE, 643);

		ASSERT_EQ(8, index);
	}

	TEST(Lesson3Tests, BinarySearchNotFound1_test)
	{
		int arr[] = { 0, 1, 54, 156, 234, 264, 346, 642,  643 };
		int SIZE = sizeof(arr) / sizeof(int);

		int index = BinarySearch(arr, SIZE, 500);

		ASSERT_EQ(-1, index);
	}

	TEST(Lesson3Tests, BinarySearchNotFound2_test)
	{
		int arr[] = { 0, 1, 54, 156, 234, 264, 346, 642,  643 };
		int SIZE = sizeof(arr) / sizeof(int);

		int index = BinarySearch(arr, SIZE, -500);

		ASSERT_EQ(-1, index);
	}

	//-------------Задача про короля----------------
	TEST(Lesson3Tests, KingMovesWithoutBariers_test)
	{
		ClearBoard();

		point target;
		target.X = 4;
		target.Y = 4;

		point barriers[1];
		int moves = L4_ex_1(0, 0, target, barriers, 0);
		ASSERT_EQ(70, moves);
	}

    TEST(Lesson3Tests, KingMovesWithOneBariers_test)
    {
        ClearBoard();

        point target;
        target.X = 2;
        target.Y = 1;

        point barriers[1];
        barriers[0].X = 0;
        barriers[0].Y = 1;

        int moves = L4_ex_1(0, 0, target, barriers, 1);
        ASSERT_EQ(2, moves);
    }

    // Расстановка препятствий как в презентации
    TEST(Lesson3Tests, KingMovesWithHWBariers_test)
    {
        ClearBoard();

        point target;
        target.X = 4;
        target.Y = 4;

        point barriers[3];
        barriers[0].X = 1;
        barriers[0].Y = 1;

        barriers[1].X = 1;
        barriers[1].Y = 3;

        barriers[2].X = 3;
        barriers[2].Y = 2;

        int moves = L4_ex_1(0, 0, target, barriers, 3);
        ASSERT_EQ(10, moves);
    }

}