#include "main.h"

/**
  * create_file - Entry point of this program
  *
  * @filename: the name of file to be created
  * @text_content: content to be written to file
  *
  * Return: -1 and 1 depends on output
  */

int create_file(const char *filename, char *text_content)
{
	FILE *FilePointer;
	struct stat filestat;

	if (stat(filename, &filestat) == 0)
		remove(filename);

	if (text_content == NULL)
	{
		FilePointer = fopen(filename, "w");
		chmod(filename, S_IRUSR | S_IWUSR);
	}
	else
	{
		FilePointer = fopen(filename, "w");
		chmod(filename, S_IRUSR | S_IWUSR);
		fprintf(FilePointer, "%s", text_content);
	}

	if (filename == NULL)
		return (-1);

	fclose(FilePointer);

	return (1);
}
