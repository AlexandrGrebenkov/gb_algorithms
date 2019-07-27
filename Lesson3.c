#include "Lesson3.h"

/// Функция обмена значений местами
void swap(int* a, int* b);

/// Обычная сортировка пузырьком
/// \param arr массив
/// \param len длина массива
void BubbleSort(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

/// Обычная Оптимизированная сортировка пузырьком
/// \param arr массив
/// \param len длина массива
void BubbleSortOptim(int* arr, int len)
{
	while (--len > 0)
	{
		for (int j = 0; j < len; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

/// Обычная Шейкерная сортировка
/// \param arr массив
/// \param len длина массива
void ShakerSort(int* arr, int len)
{
	int loIndex = 0;
	int hiIndex = len;

	while (hiIndex - loIndex > 0)
	{
		if ((hiIndex + loIndex) % 2 == 0)
		{
			for (int j = loIndex; j < hiIndex - 1; j++)
			{
				if (arr[j] > arr[j + 1])
					swap(&arr[j], &arr[j + 1]);
			}
			hiIndex--;
		}
		else
		{
			for (int j = hiIndex; j > loIndex; j--)
			{
				if (arr[j - 1] > arr[j])
					swap(&arr[j - 1], &arr[j]);
			}
			loIndex++;
		}
	}
}

/// Рекурсивный линейный поиск
/// \param arr массив
/// \param len длина массива
int LinearSearch(int* arr, int len, int v)
{
	if (len == 0)
		return -1;
	if (arr[len - 1] == v)
		return len - 1;
	LinearSearch(arr, --len, v);
}


void swap(int* a, int* b)
{
	int t = *a + *b;
	*b = t - *b;
	*a = t - *a;
}