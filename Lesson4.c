#include "Lesson4.h"


int BinarySearch(int* arr, int len, int v)
{
	if (len == 0) return -1; // Значение не найдено
	int midIndex = len / 2 + len % 2; // Индекс середины массива
	int midValue = arr[midIndex]; // значение середины массива
	if (v == midValue) // Нашли число в середине массива
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

int L4_ex_1(int kingPositionX, int kingPositionY, point target, point* barriers, int barriersCount)
{
	if (kingPositionX > 8 ||
		kingPositionY > 8)
		return 0; // Вышли за границы доски

	if (kingPositionX == target.X &&
		kingPositionY == target.Y)
		return 1; // Пришли в нужное место

    // Проверяем препятствия:
    for (int i = 0; i < barriersCount; ++i)
    {
        if (kingPositionX == barriers[i].X &&
            kingPositionY == barriers[i].Y)
            return 0; // Наткнулись на препятствие
    }

	return L4_ex_1(kingPositionX + 1, kingPositionY, target, barriers, barriersCount) + L4_ex_1(kingPositionX, kingPositionY + 1, target, barriers, barriersCount);
}



void ClearBoard()
{
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
		{
			ChessBoard[i][j] == 0;
		}
}