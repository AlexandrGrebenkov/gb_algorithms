#include "Lesson4.h"
#include <stdlib.h>

//------------Бинарный поиск---------------
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

//-------------Задача про короля----------------
int L4_ex_1(point kingPosition, point target, point* barriers, int barriersCount)
{
	if (kingPosition.X > 8 ||
		kingPosition.Y > 8)
		return 0; // Вышли за границы доски

	if (kingPosition.X == target.X &&
		kingPosition.Y == target.Y)
		return 1; // Пришли в нужное место

	// Проверяем препятствия:
	for (int i = 0; i < barriersCount; ++i)
	{
		if (kingPosition.X == barriers[i].X &&
			kingPosition.Y == barriers[i].Y)
			return 0; // Наткнулись на препятствие
	}
	point p1, p2;
	p1 = p2 = kingPosition;
	p1.X++; p2.Y++;
	return L4_ex_1(p1, target, barriers, barriersCount) + L4_ex_1(p2, target, barriers, barriersCount);
}

//--------------Задача про коня------------------
point* GetAvailableMoves(point current);
int PointIsFree(point p);
void SetPoint(point p, int n);
void ResetPoint(point p);
point FindPoint(int n);


// Решение задачи с конём. Работает на доске 5х5, но на доске 8х8 решение слишком продолжительное.
// принцип - перебираем только возможные ходы коня, вместо всей доски, как в задаче с ферзями.
// допущение, которое я принял - начальное значение всегда в точке 0, 0. Основная причина - слишком
// много if'ов для начального значения и список доступных ходов для неустановленного коня
// ещё недостаток - использование глобального массива process[], помимо массива ChessBoard.
int L4_ex_2(int n)
{
	if (n == ROWS * COLS) return 1; // Прошли всё поле - выходим
	point current = FindPoint(n);   // Получаем координаты расположения для текущего шага
	point* moves = GetAvailableMoves(current); // Получаем возможные ходы из текущей позиции
	int moveCntr = 0; // Счётчик по доступным ходам
	if (n == 1) // первый запуск - устанавливаем коня на первую клетку
		SetPoint(current, 1);

	// перебор всех доступных ходов:
	while (moves[moveCntr].X != -1)
	{
		if (PointIsFree(moves[moveCntr]))
		{
			SetPoint(moves[moveCntr], n + 1);
			if (L4_ex_2(n + 1))
			{
				free(moves);
				return 1;
			}
			ResetPoint(moves[moveCntr]);
		}
		moveCntr++;
	}
	free(moves);
	return  0;
}

// процесс решения задачи - используется для оптимизации поиска текущей позиции
// по содержимому можно воспроизвести решение
point process[ROWS * COLS];

point FindPoint(int n)
{
	return process[n - 1];
}

/// Доступна ли эта клетка для хода?
/// \param p проверяемая клетка
/// \return 0 - на эту клетку уже ходили
int PointIsFree(point p)
{
	return ChessBoard[p.X][p.Y] == 0;
}

void SetPoint(point p, int n)
{
	ChessBoard[p.X][p.Y] = n;
	process[n - 1] = p;
}

void ResetPoint(point p)
{
	ChessBoard[p.X][p.Y] = 0;
}

/// Функция возвращает возможные ходы коня для текущей позиции
/// \param current текущая позиция на доске
/// \return указатель на массив с доступными ходами. Оканчивается на элемент со значениями -1, -1
point* GetAvailableMoves(point current)
{
	int xFlip, yFlip;
	int counter = 0;
	int xPos, yPos;
	point* arr = (point*)malloc(sizeof(point) * 9);
	if (arr == NULL) return arr;

	for (int i = 0; i < 4; i++)
	{
		xFlip = ((i >> 0) & 1) == 1 ? -1 : 1;
		yFlip = ((i >> 1) & 1) == 1 ? -1 : 1;

		// дублирование кода.. но пусть будет
		xPos = current.X + 1 * xFlip;
		yPos = current.Y + 2 * yFlip;
		if ((xPos < COLS && yPos < ROWS) &&
			(xPos >= 0 && yPos >= 0))
		{
			arr[counter].X = xPos;
			arr[counter].Y = yPos;
			counter++;
		}

		xPos = current.X + 2 * xFlip;
		yPos = current.Y + 1 * yFlip;
		if ((xPos < COLS && yPos < ROWS) &&
			(xPos >= 0 && yPos >= 0))
		{
			arr[counter].X = xPos;
			arr[counter].Y = yPos;
			counter++;
		}
	}

	arr[counter].X = -1;
	arr[counter].Y = -1;
	return arr;
}

