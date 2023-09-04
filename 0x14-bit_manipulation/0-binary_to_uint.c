#include <stdio.h>
#include <stddef.h>
#include "main.h"

/**
 * binary_to_uint - converts a binary number to an
 * unsigned int.
 * @b: binary.
 *
 * Return: unsigned int.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int DecimalValue = 0;
	int binary = 0, rem = 0, weight = 1;

	if (!b)
		return (0);

	while (*b != '\0')
	{
		if (*b >= '0' && *b <= '9')
		{
			binary = binary * 10 + (*b - '0');
		}
		else
		{
			break;
		}
		b++;
	}

	while (binary != 0)
	{
		rem = binary % 10;
		DecimalValue = DecimalValue + rem * weight;
		binary = binary / 10;
		weight = weight * 2;

	}
	return (DecimalValue);
}
