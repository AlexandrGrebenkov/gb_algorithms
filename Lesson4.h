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
