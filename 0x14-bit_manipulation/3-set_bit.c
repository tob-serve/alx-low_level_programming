#include "main.h"

/**
 * set_bit - Function to set a bit to 1 at a given index
 *
 * @n: The integer to modify
 * @index: The index of the bit to change to 1
 * Return: 0
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bitmask;

	if (index > 63)
		return -1;

	bitmask = 1UL << index;

	*n = *n | bitmask;

	return (1);
}

