#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: always 0 for success
 */

int main(void)
{
	int j;

	for (j = 97; j <= 122; j++)
	{
		if (j == 101 || j == 113)
		{
			j++;
			continue;
		}
		putchar(j);
	}
	putchar('\n');

	return (0);
}
