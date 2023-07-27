#include "main.h"

/**
  * _abs - Computes the absolute value
  * of an integer.
  *
  * @d: input number as an integer
  *
  * Return: absolute value
  */

int _abs(int d)
{
	if (d >= 0)
	{
		return (d);
	}
	else
	{
		return (d + -d * 2);
	}
}
