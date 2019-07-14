#include "Lesson4.h"


int BinarySearch(int* arr, int len, int v)
{
	if (len == 0) return -1; // �������� �� �������
	int midIndex = len / 2 + len % 2; // ������ �������� �������
	int midValue = arr[midIndex]; // �������� �������� �������
	if (v == midValue) // ����� ����� � �������� �������
		return midIndex;
	if (v > midValue)
	{
		int index = BinarySearch(arr + midIndex, len / 2, v);
		return index == -1 ? index : index + midIndex;
	}
	else
	{
		return BinarySearch(arr, len / 2, v);
	}
}