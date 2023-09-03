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
	unsigned int dec, weight = 1;
	int rem;

	while (*b != 0)
	{
		rem = b % 10;
		dec = dec + rem*weight;
		//getting the binary minus the last one we walked on
		binary = binary / 10;
		// incrementing weight by 2
		weight = weight*2;
	}
	return dec;
}
