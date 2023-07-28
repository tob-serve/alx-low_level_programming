#include <stdio.h>

/**
  * main - Entry point
  *
  * Return: always 0 for success
  */

int main(void)
{
	int j = 0;

	while (j <= 9)
	{
		putchar(j + 48);
		j++;
	}
	putchar('\n');

	return (0);
}
