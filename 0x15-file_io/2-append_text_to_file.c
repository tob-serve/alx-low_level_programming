#include "main.h"

/**
  *
  */

int append_text_to_file(const char *filename, char *text_content)
{
	FILE *FilePointer;
	struct stat filestat;

	if (stat(filename, &filestat) != 0)
		return (-1);

	else
	{
		if (text_content == NULL)
		{
			return (1);
		}
		else
		{
			FilePointer = fopen(filename, "a+");
			
			if (FilePointer != NULL)
			{
				fprintf(FilePointer, "%s", text_content);
			}
		}
	}

	fclose(FilePointer);

	return (1);
}
