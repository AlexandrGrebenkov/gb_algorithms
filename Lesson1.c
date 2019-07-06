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
	if (d < 0) // �� �� �� ����� �������������� � ������������ �������?
	{
		result.r1 = result.r2 = 0;
		return result;
	}

	result.r1 = (-b - sqrt(d)) / (2 * a);
	result.r2 = (-b + sqrt(d)) / (2 * a);

	return result;
}



char str_3[20]; // ������ ��� ������� �3. ���� - �����, �� � �� ���� 
				// ����� ��� ���������� ������ ���� ����� cmake, ��� �� ������������ malloc

char* exec_3(int age)
{
	int lastDigit = age % 10;
	if (lastDigit == 1)
	{
		sprintf(str_3, "%d ���", age);
		return str_3;
	}
	if (lastDigit < 4 && lastDigit != 0)
	{
		sprintf(str_3, "%d ����", age);
		return str_3;
	}
	sprintf(str_3, "%d ���", age);
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
		int temp = 0;	// ���� ����� ��������������� ���������� �����, ��������� �� ��������� ���� square
		int j = 0;		// ������ ����� � ����� square, ������� ����� ����������� � temp
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
// ������ �� ��������������� ���������: O(n*m) ��� ����� ������� ��� O(n)?
