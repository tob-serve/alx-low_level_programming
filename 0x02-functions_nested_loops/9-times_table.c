#include "main.h"

/**
  * main - Entry point of program
  *
  * times_table
  *
  * Return: Always 0 for success
  */

void times_table(void)
{
	int i. j, pro;

	for (i = 0; i < 10, i++)
	{
		_putchar('0');

		for (j = 0; j < 10; j++)
		{
			_putchar(',');
			_putchar(' ');
			
			pro = i * j;

			if (pto <= 9)
			{
				_putchar(' ');

				else
				{
					_putchar((pro /10) + '0');
					_putchar((pro % 10) + '0');
				}
			}
		}

		_putchar(`\n`)
	}
}
