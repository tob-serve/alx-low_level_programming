#include "main.h"
/**
  * print_sign - Determines if the input
  * greater, equal or less than zero
  *
  * @n: the input number as an integer
  *
  * Returm: 1 i s greater than zero, 0 is zero
  * -1 is less than zero
  */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar(43);
		return (1);
	}
	else if (n < 0)
	{
		_putchar(45);
		return (-1);
	}
	_putchar('\n')
}
