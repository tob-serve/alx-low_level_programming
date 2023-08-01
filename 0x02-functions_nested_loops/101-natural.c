#include <stdio.h>

/**
  * main - Entry point of program
  *
  * Return: Always 0 for success
  */

int main(void)
{
	int i;
	int total;

	for (int d = 0; d < 1024; d++)
	{
		if (d % 3 == 0 || d % 5 == 0)
		{
			total += d;
		}
	}

	printf("%d\n", total);

	return (0);
}
