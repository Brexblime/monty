#include "monty.h"
#include <stdlib.h>

/**
 * error - error handler
 * @code: code for exit status
 * @msg: string message
 * @arg: argument for message
 * @type: type of the arg
 * Return: exit status
 */
int error(int code, char *msg, void *arg, char type)
{
	FILE *output = stderr;

	if (type == 'd')
	{
		fprintf(output, msg, *(int *)arg);
	}
	else if (type == 's')
	{
		fprintf(output, msg, (char *)arg);
	}
	else if (type == 'u')
	{
		fprintf(output, msg, *(unsigned int *)arg);
	}
	else if (type == 'n')
	{
		fprintf(output, msg, (void *)arg);
	}
	else
	{
		fprintf(output, "Invalid type specified.\n");
	}
	exit(code);
}
