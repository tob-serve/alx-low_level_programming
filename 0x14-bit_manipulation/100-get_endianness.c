#include "main.h"

/**
  * get_endianness - check the system byte order
  * Return: 0 if big endian and 1 if little endian
  */

int get_endianness(void)
{
	int x = 1;
	int LiBi;

	LiBi = (int) (((char *)&x)[0]);
	return (LiBi);
}
