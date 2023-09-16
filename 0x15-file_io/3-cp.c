#include "main.h"

/**
  * ArgumentCheck - Entry point of program
  *
  * @argc:argument count
  *
  * Return: varies depend on result
  */

int ArgumentCheck(int argc)
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * main - Entry point of program
 *
 * @argc:argument count
 * @argv: argument vector
 *
 * Return: varies depend on result
 */

int main(int argc, char *argv[])
{
	int FileDesOne;
	struct stat FileState;
	FILE *TempFd = 0;


	ArgumentCheck(argc);

	if (stat(argv[2], &FileState) == 0)
	{
		TempFd = fopen(argv[2], "w");
		fclose(TempFd);
	}
	else
	{
		FileDesOne = open(argv[2], 0_RDWR | O_CREAT, 0664)
	}
	if (stat(argv[1], &FileState) != 0)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	while ((bytesRead = read(sourceFd, buffer, sizeof(buffer))) > 0)
	{
		bytesWritten = write(destinationFd, buffer, bytesRead);
	}
	fclose(TempFd);
}
