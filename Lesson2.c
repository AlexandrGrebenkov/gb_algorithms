#include "Lesson2.h"

int L2_exec_1(uint8_t input)
{
	if (input < 2)
		return input;
	int val = L2_exec_1(input / 2) * 10 + input % 2;
	return val;
}

int L2_exec_2a(int a, int b)
{
	int result = 1;
	while (b-- > 0)
	{
		result *= a;
	}
	return result;
}

int L2_exec_2b(int a, int b)
{
	if (b == 0)
		return 1;
	return L2_exec_2b(a, --b) * a;
}

int L2_exec_2c(int a, int b)
{
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return L2_exec_2c(a, b - 1) * a;
	else
	{
		int tmp = L2_exec_2c(a, b / 2);
		return tmp * tmp;
	}
}
