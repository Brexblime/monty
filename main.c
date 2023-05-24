#define _POSIX_C_SOURCE 200809L
#include "monty.h"
data_t data = {NULL, NULL, NULL, 0};
/**
 * main - where the program start executing
 * @argc: number of argument
 * @argv: list of argument
 * Return: 0 in success
*/
int main(int argc, const char *const argv[])
{
	const char *filename;
	FILE *bytecode_file;
	char *line = NULL;
	size_t size = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
		error(EXIT_FAILURE, "USAGE: monty file\n", " ", 'n');
	filename = argv[1];
	bytecode_file = fopen(filename, "r");
	data.bytecode_file = bytecode_file;
	if (!bytecode_file)
		error(EXIT_FAILURE, "Error: Can't open file %s\n", (char *)argv[1], 's');
	while (_getline(&line, &size, bytecode_file) != -1)
	{
		line_number++;
		data.line = line;
		if (execute(line, &stack, line_number, bytecode_file) != 0)
			error(EXIT_FAILURE, "Error: Failed to execute line %u\n"
				 , (void *)&line_number, 'u');
		free(line);
		line = NULL;
		size = 0;
	}
	if (ferror(bytecode_file))
		error(EXIT_FAILURE, "Error: Failed to read file %s\n"
				, (char *)filename, 's');
	clean_s(stack);
	fclose(bytecode_file);
	return (EXIT_SUCCESS);
}
