#include "monty.h"

/**
 * mul - multiplies the second top element of stack with top element of the stack
 * @stack: pointer to the stack
 * @line_number: current line number
*/
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
