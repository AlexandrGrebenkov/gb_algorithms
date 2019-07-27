#include "gtest/gtest.h"
#include "Lesson3.h"
#include <stdlib.h>

namespace
{
	void fillArray(int* arr, int len);
	int arrayIsSorted(int* arr, int len);

	TEST(Lesson3Tests, BubbleSort_test)
	{
		const int SIZE = 100;
		int arr[SIZE];
		fillArray(arr, SIZE);

		BubbleSort(arr, SIZE);

		ASSERT_EQ(1, arrayIsSorted(arr, SIZE));
	}

	TEST(Lesson3Tests, BubbleSortOptim_test)
	{
		const int SIZE = 100;
		int arr[SIZE];
		fillArray(arr, SIZE);

		BubbleSortOptim(arr, SIZE);

		ASSERT_EQ(1, arrayIsSorted(arr, SIZE));
	}

	TEST(Lesson3Tests, ShakerSort_test)
	{
		const int SIZE = 100;
		int arr[SIZE];
		fillArray(arr, SIZE);

		ShakerSort(arr, SIZE);

		ASSERT_EQ(1, arrayIsSorted(arr, SIZE));
	}

	TEST(Lesson3Tests, LinearSearch_test)
	{
		int arr[] = { 0, 54, 234, 264, 156, 643, 642, 346 , 1 };
		int SIZE = sizeof(arr) / sizeof(int);

		int index = LinearSearch(arr, SIZE, 234);

		ASSERT_EQ(2, index);
	}

	TEST(Lesson3Tests, LinearSearchNotFound_test)
	{
		int arr[] = { 0, 54, 234, 264, 156, 643, 642, 346 , 1 };
		int SIZE = sizeof(arr) / sizeof(int);

		int index = LinearSearch(arr, SIZE, 500);

		ASSERT_EQ(-1, index);
	}



	void fillArray(int* arr, int len)
	{
		int i;
		for (i = 0; i < len; i++)
			arr[i] = rand() % 100;
	}

	int arrayIsSorted(int* arr, int len)
	{
		for (int i = 0; i < len - 1; ++i)
		{
			if (*(arr + i) > * (arr + i + 1))
				return 0;
		}
		return 1;
	}

}