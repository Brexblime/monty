#include "monty.h"

/**
 * nop - does nothing
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode being executed
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
