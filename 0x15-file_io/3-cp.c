#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * file_toCheck - checks if file_to exist
  * it does its content gets cleard for new input
  *
  * @SecArgv: name of to copy to
  */

void file_toCheck(char *SecArgv)
{
	struct stat filestat;
	FILE *FilePointer;
	int FileDes = 0;

	if (stat(SecArgv, &filestat) == 0)
	{
		FilePointer = fopen(SecArgv, "w");
		fclose(FilePointer);
	}
	if (stat(SecArgv, &filestat) != 0)
	{
		FileDes = open(SecArgv, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	}
	close(FileDes);
}

/**
  * file_fromCheck -  checks if file_from exist if it dont
  * return code 98
  *
  * @FirstArgv: first agrgument vector
  */

void file_fromCheck(char *FirstArgv)
{
	struct stat filestat;

	if (stat(FirstArgv, &filestat) != 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", FirstArgv);
		exit(98);
	}
}

/**
  * Copyfile_fromfile_to - copys file_from to _file_to
  *
  * @FirstArgv: first file name
  * @SecArgv: second file name
  */

void Copyfile_fromfile_to(char *FirstArgv, char *SecArgv)
{
	int FileDesOne = -1, FileDesTwo = -1;
	char buffer[1024];
	ssize_t BytesRead, BytesWritten;
	mode_t old_umask = umask(0);

	FileDesOne = open(FirstArgv, O_RDONLY);
	umask(old_umask);
	if (FileDesOne == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", FirstArgv);
		exit(98);
	}

	FileDesTwo = open(SecArgv, O_RDWR);
	if (FileDesTwo == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", SecArgv);
		exit(99);
	}

	while ((BytesRead = read(FileDesOne, buffer, sizeof(buffer))) > 0)
	{
		BytesWritten = write(FileDesTwo, buffer, BytesRead);

		if  (BytesWritten != BytesRead)
		{
			fprintf(stderr, "Error: Can't write to %s\n", SecArgv);
			exit(99);
		}
	}

	if (close(FileDesOne) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", FileDesOne);
		exit(100);
	}
	if (close(FileDesTwo) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", FileDesTwo);
		exit(100);
	}
}

/**
  * main - Entry point of program
  *
  * @argc: argument count
  * @argv: argument vector
  *
  * Return: 0 for success
  */

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to");
		exit(97);
	}

	file_toCheck(argv[2]);

	file_fromCheck(argv[1]);

	Copyfile_fromfile_to(argv[1], argv[2]);

	return (0);
}
