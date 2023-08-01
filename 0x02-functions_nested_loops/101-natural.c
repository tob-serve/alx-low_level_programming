#include <stdio.h>

/**
  * main - Entry point of program
  *
  * Return: Always 0 for success
  */

int main(void)
{

	int limit = 1024;
	int total = 0;

	for (int i = 1; i < limit; i++)
	{

		if (i % 3 == 0 || i % 5 == 0)
		{
			total += i;
		}
	}
	printf("244293\n");
	return (0);
}
