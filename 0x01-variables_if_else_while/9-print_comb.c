#include <stdio.h>

/**
  * main - Entry point
  *
  * Return: awlays 0 for success
  */

int main(void)
{
	int d = 48;

	while (d <= 57)
	{
		putchar(d);
		d++;

		putchar(',');
		putchar(' ');
	}
	putchar('\n');

	return(0);
}
