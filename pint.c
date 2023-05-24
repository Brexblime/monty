#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the opcode being executed
*/
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        error(EXIT_FAILURE, "L%u: can't pint, stack empty\n",
			(void *)&line_number, 'u');
    }

    printf("%d\n", (*stack)->n);
}
