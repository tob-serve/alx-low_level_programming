#include "main.h"

/**
  * append_text_to_file - is the Entry point of program
  *
  * @filename: name to be given to file created
  * @text_content: content to be written in file
  *
  * Return: 1 or -1 for success or fall
  */

int append_text_to_file(const char *filename, char *text_content)
{
	FILE *FilePointer;
	struct stat filestat;

	if (filename == NULL)
		return (-1);

	if (stat(filename, &filestat) != 0)
		return (-1);

	if (stat(filename, &filestat) == 0)
	{
		FilePointer = fopen(filename, "a+");
	}
	if (FilePointer == NULL)
		return (-1);
	if (text_content != NULL)
		fprintf(FilePointer, "%s", text_content);

		fclose(FilePointer);
	}

	return (1);
}
