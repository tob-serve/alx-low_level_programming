#include "main.h"

/**
  * file_fromCheck - checks if file_to exist if
  * it does truncate
  *
  * @argv: second argument vector file name
  *
  * Return: 0 for sucess
  */

int file_fromCheck(char *argv)
{
	struct stat filestat;

	if (stat(argv, &filestat) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv);
		exit(98);
	}

	return (0);
}

/**
  * CopyFiles - copy files from one to another
  *
  * @argvOne: first file name
  * @argvTwo: second file name
  *
  * Return: 0 for success
  */

int CopyFiles(char *argvOne, char *argvTwo)
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[1024];

	fd_from = open(argvOne, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argvOne);
		exit(98);
	}
	fd_to = open(argvTwo, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argvTwo);
		exit(99);
	}
	while ((bytes_read = read(fd_from, buffer, 1024)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argvTwo);
			exit(99);
		}
	}
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close %d\n", fd_to);
		exit(100);
	}
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close %d\n", fd_to);
		exit(100);
	}
	return (0);


}

/**
  * main - Entry point of program
  *
  * @argc: argu,ent count
  * @argv: argument vector
  *
  * Return: always 0 for success
  */

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_fromCheck(argv[1]);

	CopyFiles(argv[1], argv[2]);

	return (0);
}
