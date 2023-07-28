#include <stdio.h>

/**
  * main - Entry point
  *
  * Return: Always 0 for success
  */

int main(void)
{
	int d = 122;

	while (d >= 97)
	{
		putchar(d);
		d--;
	}
	putchar('\n');

	return (0);
}
