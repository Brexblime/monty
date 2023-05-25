#include "monty.h"

/**
 * divide - divides the second top element of the stack by the top element
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode being executed
*/
void divide(stack_t **stack, unsigned int line_number)
{
	int div_result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	div_result = (*stack)->next->n / (*stack)->n;

	pop(stack, line_number);
	(*stack)->n = div_result;
}
