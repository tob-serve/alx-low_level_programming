#include "main.h"

/**
  * ArgumentCheck - checks if the argument input is
  * up to 3
  *
  * @argc: argument count
  * @argv: argument vector
  * Return: int value 97
  */

void ArgumentCheck(int *argc)
{
	if (*argc != 3)
	{
		fprintf(stderr, "Usage: cp file_from file_to");
		exit(97);
	}
}

/**
  * file_toCheck: checks if file_to already exist if
  * it does its content gets cleard for new input 
  *
  * @argv[2]: name of to copy to
  */

void file_toCheck(char *SecArgv)
{
	struct stat filestat;
	FILE *FilePointer;
	int FileDes = 0;
	mode_t permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (stat(SecArgv, &filestat) == 0)
	{
		FilePointer = fopen(SecArgv, "w");
		fclose(FilePointer);
	}
	if (stat(SecArgv, &filestat) != 0)
	{
		FileDes = open(SecArgv, O_WRONLY | O_CREAT | O_TRUNC, permissions);
		close(FileDes);
	}
	close(FileDes);
}

/**
  * file_fromCheck: checks if file_from exist if it dont
  * return code 98
  *
  * @FirstArgv: first agrgument vector
  */

void file_fromCheck(char *FirstArgv)
{
	struct stat filestat;

	if (stat(FirstArgv, &filestat) != 0)
	{
		fprintf(stderr, "Error: can't read from %s\n", FirstArgv);
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

	FileDesOne = open(FirstArgv, O_RDONLY);
	if (FileDesOne == -1)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", FirstArgv);
		exit(98);
	}

	while ((BytesRead = read(*FirstArgv, buffer, sizeof(buffer))) > 0)
	{
		BytesWritten = write(*SecArgv, buffer, BytesRead);
	}

	if  (BytesWritten != BytesRead)
	{
		fprintf(stderr, "Error: can't write to %s\n", SecArgv);
		exit(99);
	}
	if (close(FileDesOne) != 0)
	{
		fprintf(stderr, "Error: can't close %d\n", FileDesOne);
		exit(100);
	}
	if (close(FileDesTwo) != 0)
	{
		fprintf(stderr, "Error: can't close %d\n", FileDesTwo);
		exit(100);
	}
	close(FileDesOne);
	close(FileDesTwo);
}

/**
  * main - Entry point of program
  *
  * @argc: argument count
  * @argv[]: argument vector
  */

int main(int argc, char **argv)
{
	ArgumentCheck(&argc);

	file_toCheck(argv[2]);

	file_fromCheck(argv[1]);

	Copyfile_fromfile_to(argv[1], argv[2]);

	return(0);
}
