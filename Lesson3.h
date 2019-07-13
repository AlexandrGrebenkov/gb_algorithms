#ifndef GB_ALGORITHMS_LESSON3_H
#define GB_ALGORITHMS_LESSON3_H

#ifdef __cplusplus
extern "C" {
#endif

	/*
	1. Оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и не оптимизированной программы. Написать функции сортировки, которые возвращают количество операций.
	2. *Реализовать шейкерную сортировку.
	3. рекурсивное решение задачи линейного поиска
	 */

	void BubbleSort(int* arr, int len);
	void BubbleSortOptim(int* arr, int len);
	void ShakerSort(int* arr, int len);
	int LinearSearch(int* arr, int len, int v);

#ifdef __cplusplus
}
#endif
#endif //GB_ALGORITHMS_LESSON3_H
