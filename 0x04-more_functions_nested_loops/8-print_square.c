#include "main.h"

/**
  * print_square - prints a square
  * @size: calculations for square
  */

void print_square(int size)
{
	int count;
	int lines;

	if (size <= 0)
	{
		_putchar('\n');
	}
	for (count = 0; count < size; count++)
	{
		for (lines = 0; lines < size; lines++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
