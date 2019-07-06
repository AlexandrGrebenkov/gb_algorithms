#include "Lesson1.h"
#include <math.h>
#include <stdio.h>


double exec_1(double height, double mass)
{
	return mass / (height * height);
}


roots exec_2(double* rates)
{
	roots result;
	double a = *(rates + 0);
	double b = *(rates + 1);
	double c = *(rates + 2);

	double d = b * b - 4 * a * c;
	if (d < 0) // Мы же не будем заморачиваться с комплексными числами?
	{
		result.r1 = result.r2 = 0;
		return result;
	}

	result.r1 = (-b - sqrt(d)) / (2 * a);
	result.r2 = (-b + sqrt(d)) / (2 * a);

	return result;
}



char str_3[20]; // строка для задания №3. Знаю - плохо, но я не смог 
				// найти где установить размер кучи через cmake, что бы пользоваться malloc

char* exec_3(int age)
{
	int lastDigit = age % 10;
	if (lastDigit == 1)
	{
		sprintf(str_3, "%d год", age);
		return str_3;
	}
	if (lastDigit < 4 && lastDigit != 0)
	{
		sprintf(str_3, "%d года", age);
		return str_3;
	}
	sprintf(str_3, "%d лет", age);
	return str_3;
}


boolean exec_4(point p1, point p2)
{
	if ((p1.x % 2 == p1.y % 2) &&
		(p2.x % 2 == p2.y % 2))
	{
		return _true;
	}
	return _false;
}

int digits_5[100];
int PowOf10(int digit, int rate)
{
	while (rate--)
	{
		digit *= 10;
	}
	return digit;
}

int* exec_5(int n)
{
	int digitCounter = 0;
	int square;
	
	for (int i = 0; i < n; i++)
	{
		square = i * i;
		int temp = 0;	// Сюда будем последовательно записывать число, собранное из последних цифр square
		int j = 0;		// Индекс цифры с конца square, которую будем приписывать к temp
		while (temp <= i)
		{
			temp += PowOf10(square % 10, j++);
			if (temp == i)
			{
				digits_5[digitCounter++] = i;
				break;
			}
			square /= 10;
		}
	}
	return digits_5;
}
// Вопрос по асимптотической сложности: O(n*m) или можно считать как O(n)?
