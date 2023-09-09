#include "main.h"
/**
  * read_textfile - reads text files and prints it int
  * POSIX
  *
  * @filename: file to read
  * @letters: amount of letters to read and print
  * Return: bytes written an dread
  */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t bytesRead;
	ssize_t bytesWritten;
	int file_descriptor;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = (char *)malloc(letters + 1);

	file_descriptor = open(filename, O_RDONLY);

	if (file_descriptor == -1)
		return (0);

	bytesRead = read(file_descriptor, buffer, letters);

	buffer[bytesRead] = '\0';

	bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);

	free(buffer);
	close(file_descriptor);

	return (bytesWritten);
}
