#include "main.h"

/**
  * print_last_digits - prints the las digits
  * of the number given.
  *
  * @n: input number as an integer
  *
  * Return: last digits.
  */

int print_last_digits(int n)
{
	int l;

	l = n % 10;

	if (l < 0)
	{
		_putchar(-l + 45);
		return (-l);
	}
	else
	{
		_putchar(l + 48);
		return (l);
	}
}
