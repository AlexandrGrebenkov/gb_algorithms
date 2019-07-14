#include "gtest/gtest.h"
#include "Lesson4.h"

namespace
{
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
}