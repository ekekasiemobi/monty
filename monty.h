#ifndef MONTY_H
#define MONTY_H
#define BUF_SIZE 1024

#include <stdio.h>
#include <stdlib.h>

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

void print_error(char *message, int status);
void *add_stack_beg(stack_t **stack, unsigned int);
void *add_stack_end(stack_t **stack, unsigned int);
void *print_int(stack_t **stack, unsigned int line_count);
void *print_all(stack_t **stack, unsigned int line_count);
void _nop(stack_t **stack, unsigned int line_cont)
#endif
