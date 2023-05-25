#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct data - hold the data for using it in diffrent function
 * @argument: argument
 * @line: line
 * @bytecode_file: bytecode file data
 * @op: the change from stack to queue
*/
typedef struct data
{
	char *argument;
	char *line;
	FILE *bytecode_file;
	int op;
} data_t;
extern data_t data;
int execute(char *line, stack_t **stack, unsigned int line_number,
		FILE *bytecode_file);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);

void queue_c(stack_t **stack, unsigned int line_number);
void stack_c(stack_t **stack, unsigned int line_number);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
bool is_number(const char *str, int *value);
int error(int code, char *msg, void *arg, char type);
void clean_s(stack_t *stack);
void add_to_stack(stack_t **head, int value);
void add_to_queue(stack_t **head, int value);
#endif
