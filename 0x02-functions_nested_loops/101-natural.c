#include <stdio.h>

/**
  * main - Entry point of program
  *
  * Return: Always 0 for success
  */

int main()
{

	int limit = 1024;
	int total = 0;
	int i;

	while (i < limit)
	{
		i++;

		if (i % 3 == 0 || i % 5 == 0)
		{
			total += i;
		}
		printf("%d\n", total);
	}
	return (0);
}
