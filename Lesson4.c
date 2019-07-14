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


point* GetAvailableMoves(point current);
int IsPointFree(point p);
void SetPoint(point p, int n);
void ResetPoint(point p);
point FindPoint(int n);

int L4_ex_2(int n)
{
	if (n == ROWS * COLS + 1) return 1; // Прошли всё поле - выходим
	point current = FindPoint(n);
	point* moves = GetAvailableMoves(current);
	int moveCntr = 0;
	if (n == 1)
		SetPoint(current, 1);
	// перебор всех доступных ходов:
	while (moves[moveCntr].X != -1)
	{
		if (IsPointFree(moves[moveCntr]))
		{
			SetPoint(moves[moveCntr], n + 1);
			if (L4_ex_2(n + 1))
				return 1;
			if (n == 1)
			{
				n = 1;
			}
			ResetPoint(moves[moveCntr]);
		}
		moveCntr++;
	}
	return  0;
}

point FindPoint(int n)
{
	point p;
	p.X = 0;
	p.Y = 0;
	if (n == 1)
		return p;
	for (int i = 0; i < COLS; ++i)
		for (int j = 0; j < ROWS; ++j)
		{
			if (ChessBoard[i][j] == n)
			{
				p.X = i;
				p.Y = j;
				return p;
			}
		}
}

/// Доступна ли эта клетка для хода?
/// \param p проверяемая клетка
/// \return 0 - на эту клетку уже ходили
int IsPointFree(point p)
{
	return ChessBoard[p.X][p.Y] == 0;
}

void SetPoint(point p, int n)
{
	ChessBoard[p.X][p.Y] = n;
}

void ResetPoint(point p)
{
	ChessBoard[p.X][p.Y] = 0;
}

point availableMoves[9]; // доступные ходы для текущей позиции (8 возможных + 1 терминальная ячейка со значениями -1, -1)

/// Функция возвращает возможные ходы коня для текущей позиции
/// \param current текущая позиция на доске
/// \return указатель на массив с доступными ходами. Оканчивается на элемент со значениями -1, -1
point* GetAvailableMoves(point current)
{
	int xFlip, yFlip;
	int counter = 0;
	int xPos, yPos;
	for (int i = 0; i < 4; i++)
	{
		xFlip = ((i >> 0) & 1) == 1 ? -1 : 1;
		yFlip = ((i >> 1) & 1) == 1 ? -1 : 1;

		xPos = current.X + 1 * xFlip;
		yPos = current.Y + 2 * yFlip;
		if ((xPos < COLS && yPos < ROWS) &&
			(xPos >= 0 && yPos >= 0))
		{
			availableMoves[counter].X = xPos;
			availableMoves[counter].Y = yPos;
			counter++;
		}

		xPos = current.X + 2 * xFlip;
		yPos = current.Y + 1 * yFlip;
		if ((xPos < COLS && yPos < ROWS) &&
			(xPos >= 0 && yPos >= 0))
		{
			availableMoves[counter].X = xPos;
			availableMoves[counter].Y = yPos;
			counter++;
		}
	}

	availableMoves[counter].X = -1;
	availableMoves[counter].Y = -1;
	return availableMoves;
}

