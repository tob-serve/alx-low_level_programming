#include "main.h"

/**
  * main - Entrypoint of program
  *
  * @argc: argument count
  * @argv: argumant vector
  *
  * Return: int value
  */

int main(int argc, char *argv[])
{
	int FileDesFirst, FileDesSec;
	struct stat FileStat;
	char buffer[1024];
	ssize_t bytesRead;
	ssize_t bytesWritten = -1;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: cp file_from file_to");
		exit(97);
	}

	if (stat(argv[2], &FileStat) == 0)
		remove(argv[2]);

	if (stat(argv[1], &FileStat) != 0)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	FileDesFirst = open(argv[1], O_RDONLY);

	if (stat(argv[2], &FileStat) != 0)
	{
		if (FileDesFirst != 0)
		{
			fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	FileDesSec = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

	while ((bytesRead = read(FileDesFirst, buffer, sizeof(buffer))) > 0)
	{
		bytesWritten = write(FileDesSec, buffer, bytesRead);
		if (bytesWritten == -1)
		{
			fprintf(stderr, "Error: Can't write to file %s\n", argv[2]);
			close(FileDesFirst);
			close(FileDesSec);
			exit(99);
		}
	}

	if (close(FileDesFirst) == 0)
	{
		fprintf(stderr, "Error: Can't close fd %d\n", FileDesFirst);
		exit(100);
	}
	if (close(FileDesSec) == 0)
	{
		fprintf(stderr, "Error: Can't close fd %d\n", FileDesSec);
		exit(100);
	}
	return (1);

}
