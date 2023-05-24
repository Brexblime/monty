#include "monty.h"

/**
 * is_number - helps to check the number
 * @str: string
 * @value: value
 * Return: True or False / 1 or 0
*/
bool is_number(const char *str, int *value)
{
	int sign = 1, result = 0;

	if (str == NULL || *str == '\0')
		return (false);

	if (*str == '-')
	{
		sign = -1;
		str++;
	}

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (false);
		result = result * 10 + (*str - '0');
		str++;
	}
	*value = result * sign;
	return (true);
}
/**
 * clean_s - cleans the stack (free the stack)
 * @stack: stack
 * Return: Nothing
*/
void clean_s(stack_t *stack)
{
	stack_t *current = stack, *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
