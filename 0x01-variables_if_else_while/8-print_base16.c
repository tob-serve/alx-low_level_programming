#include <stdio.h>

/**
  * main - Entry point
  *
  * Return: always 0 for success
  */

int main(void)
{
	int d, e;

	for (d = 48; d <= 57; d++)
	{
		putchar(d);
	}
	for (e = 97; e <= 102; e++)
	{
		putchar(e);
	}
	putchar('\n');

	return (0);
}
