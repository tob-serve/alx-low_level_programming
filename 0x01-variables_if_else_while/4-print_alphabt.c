#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: always 0 for success
 */

int main(void)
{
	int j = 97;

	while (j <= 122)
	{
		if (j == 101 || j == 113)
		{
			j++;
			continue;
		}
		putchar(j);
		j++;
	}
	putchar('\n');

	return (0);
}
