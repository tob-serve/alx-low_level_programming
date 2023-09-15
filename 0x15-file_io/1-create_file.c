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

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
	{
		FilePointer = fopen(filename, "w");
	}
	else
	{
		FilePointer = fopen(filename, "w+");
		if (FilePointer != NULL)
		{
			fprintf(FilePointer, "%s", text_content);
		}
	}

	if (chmod(filename, S_IRUSR | S_IWUSR) != 0)
	{
		return (-1);
	}

	fclose(FilePointer);

	return (1);
}
