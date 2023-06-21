#ifndef MONTY_H
#define MONTY_H
#define BUF_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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
 * struct mont_param - line number and array of words
 * @line_number: opcode line argument
 * @arr: array of words
 * @n: integer to pass to instruction
 */
typedef struct mont_param
{
	unsigned int line_number;
	char **arr;
	int n;
	instruction_t *instruct;
} param;
void print_error(char *message, char *file);
void add_stack_beg(stack_t **stack, unsigned int);
void add_stack_end(stack_t **stack, unsigned int);
void tokenizer(char *cmd, char ***arr, ssize_t read);
void (*get_dispatch_func(char *str))(stack_t**, unsigned int);
void malloc_error(void);
extern param *mont;
void print_int(stack_t **stack, unsigned int line_count);
void print_all(stack_t **stack, unsigned int line_count);
void nop(stack_t **stack, unsigned int line_cont);
void pop(stack_t **stack, unsigned int line);
void initialize(void);
void print_line_number(unsigned int line);
void free_stack(stack_t **stack);
void free_array(void);
#endif
