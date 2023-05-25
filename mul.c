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
		error(EXIT_FAILURE, "L%u: can't mul, stack too short\n",
				(void *)&line_number, 'u');
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
