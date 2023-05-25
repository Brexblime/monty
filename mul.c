#include "monty.h"

/**
 * mul - mults the second top element of the stack with the top element
 * @stack: double pointer to the top of the stack
 * @line_number: line number being executed from the monty file
*/
void mul(stack_t **stack, unsigned int line_number)
{
	int a, b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;

	(*stack)->next->n = a * b;

	pop(stack, line_number);
}
