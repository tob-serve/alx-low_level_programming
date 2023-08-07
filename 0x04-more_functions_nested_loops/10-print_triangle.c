#include "main.h"

/**
  * print_triangle - printing triangles
  * @size: is the size of triangle
  *
  * Return: ALways 0 for success
  */

void print_triangle(int size)
{
	int row;
	int space;

	if (size <= 0)
	{
		_putchar('\n');
	}

	for (int row = 1; row <= size; row++)
	{
		for (int space = size - row; space > 0; space--)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
