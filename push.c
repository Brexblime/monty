#include "monty.h"

/**
 * push - pushes to the stack
 * @stack: stack
 * @line_number: line number
 * Return: Nothing
*/
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *argument = data.argument;

	if (argument == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!is_number(argument, &value))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (data.op == 0)
		add_to_stack(stack, value);
	else
		add_to_queue(stack, value);
}
