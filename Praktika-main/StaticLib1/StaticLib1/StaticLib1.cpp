// StaticLib1.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include <vector>

// TODO: Это пример библиотечной функции.
void sort_char(std::vector <char> &vect)
{
	int i, j;
	char temp;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10 - 1 - i; j++)
		{
			if (vect[j] > vect[j + 1])
			{
				temp = vect[j];
				vect[j] = vect[j + 1];
				vect[j + 1] = temp;
			}
		}
	}
}
