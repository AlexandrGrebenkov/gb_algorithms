#ifndef GB_ALGORITHMS_LESSON4_H
#define GB_ALGORITHMS_LESSON4_H

#ifdef __cplusplus
extern "C" {
#endif
	/*
	1. * Найти количество маршрутов шахматного короля на поле с препятствиями.
	2. *** Требуется обойти конём шахматную доску размером 8х8, пройдя через
	   все поля доски по одному разу. Здесь алгоритм решения такой же как и в
	   задаче о 8 ферзях.
	3 рекурсивное решение бинарного поиска
	*/
	typedef struct
	{
		int X;
		int Y;
	}point;

#define ROWS 5
#define COLS 5
	/// Шахматная доска 8х8
	int ChessBoard[COLS][ROWS];

	/// Поиск количества маршрутов шахматного короля на поле с препятствиями.
	/// \param kingPosition начальная позиция короля (не получилось задать позицию через структуру, т.к. в рекурсивном вызове нужно инкрементировать поля)
	/// \param target куда нужно придти
	/// \param barriers список препятствий
	/// \param barriersCount количество препятствий
	/// \return количество маршрутов
	int L4_ex_1(point kingPosition, point target, point* barriers, int barriersCount);

	/// *** Требуется обойти конём шахматную доску
	int L4_ex_2(int n);

	/// Рекурсивный бинарный поиск
	/// \param arr отсортированный массив
	/// \param len длина массива
	/// \param v искомое значение
	/// \return индекс значения
	int BinarySearch(int* arr, int len, int v);


#ifdef __cplusplus
}
#endif

#endif //GB_ALGORITHMS_LESSON4_H
