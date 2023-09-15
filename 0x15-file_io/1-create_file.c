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

	if (text_content != NULL)
		FilePointer = fopen(filename, "w");

	else
	{
		FilePointer = fopen(filename, "w");
		fprintf(FilePointer, "%s", text_content);
	}

	if (filename == NULL)
		return (-1);

	fclose(FilePointer);

	return (1);
}
