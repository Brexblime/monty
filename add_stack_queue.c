#include "monty.h"
/**
 * add_to_stack - add node to stack.
 * @head: head of stack
 * @value: data for the node
*/
void add_to_stack(stack_t **head, int value)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = value;
	newNode->prev = NULL;
	newNode->next = *head;

	if (*head != NULL)
		(*head)->prev = newNode;

	*head = newNode;
}

/**
 * add_to_queue - add node to  queue
 * @head: head of queue
 * @value: data for the node
*/
void add_to_queue(stack_t **head, int value)
{
	stack_t *newNode = malloc(sizeof(stack_t)), *current;

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = value;
	newNode->prev = NULL;
	newNode->next = NULL;

	if (*head == NULL)
		*head = newNode;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = newNode;
		newNode->prev = current;
	}
}
