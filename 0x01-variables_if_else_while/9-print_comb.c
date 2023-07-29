#include <stdio.h>

/**
  * main - Entry point
  *
  * Return: awlays 0 for success
  */

int main(void)
{
	int d = 48;

	for (d = 48; d <= 57; d++)
	{
		putchar(d);
		if (d != 57)
		{
			putchar(',');
			putchar(' ');
		}

	}
	putchar('\n');

	return(0);
}
