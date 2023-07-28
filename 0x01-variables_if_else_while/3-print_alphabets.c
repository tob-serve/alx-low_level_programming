#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: always 0 for success
 */

int main(void)
{
	int j, i;

	for (j = 97; j <= 122; j++)
	{
		putchar(j);
	}
	for (i = 65; i <= 90; i++)
	{
		putchar(i);
	}
	putchar('\n');

	return (0);
}
