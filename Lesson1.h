#ifndef LESSON1_LESSON1_H
#define LESSON1_LESSON1_H

#ifdef __cplusplus
extern "C" {
#endif

	/// Корни квадратного уравнения
	typedef struct
	{
		double r1, r2;
	} roots;

	typedef struct
	{
		int x, y;
	}point;

	typedef enum
	{
		_false = 0,
		_true
	}boolean;

	/// 1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I = m / (h * h), где m – масса тела в килограммах, h – рост в метрах.
	/// \param height – рост в метрах
	/// \param mass – масса тела в килограммах
	/// \return - индекс массы тела
	double exec_1(double height, double mass);

	/// 2. Написать программу нахождения корней заданного квадратного уравнения.
	/// \param rates коэффициенты уравнения
	/// \return корни
	roots exec_2(double* rates);

	/// 3. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе со словом «год», «года» или «лет».
	/// \param age возраст человека
	/// \return Строковое представление
	char* exec_3(int age);

	/// 4. Даны числовые координаты двух полей шахматной доски (x1, y1, x2, y2). Требуется определить, относятся ли к поля к одному цвету или нет.
	/// \param p1
	/// \param p2
	/// \return false - разные цвета, true - одинаковые
	boolean exec_4(point p1, point p2);

	/// 5.Автоморфные числа. Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата. 
	/// Например, 25 ^ 2 = 625. Напишите функцию, которая выводит на экран все автоморфные числа, меньше десяти тысяч
	int* exec_5(int n);

#ifdef __cplusplus
}
#endif

#endif //LESSON1_LESSON1_H