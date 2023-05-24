#include "monty.h"

/**
 * _getline - an implementation of getline
 * @lineptr: line pointer
 * @n: length of the line
 * @stream: the file
 * Return: length of the line
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t read;
	size_t len = 0, new_size;
	char *new_line;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	if (*lineptr == NULL)
		*n = 0;

	while ((read = (ssize_t)getc(stream)) != EOF)
	{
		if (len + 1 >= *n)
		{
			new_size = (*n == 0) ? 1 : (*n) * 2;
			new_line = realloc(*lineptr, new_size);
			if (new_line == NULL)
				return (-1);

			*lineptr = new_line;
			*n = new_size;
		}
		(*lineptr)[len++] = (char)read;
		if (read == '\n')
			break;
	}

	if (len == 0)
		return (-1);

	(*lineptr)[len] = '\0';

	return ((ssize_t)len);
}
