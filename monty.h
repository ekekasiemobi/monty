#ifndef MONTY_H
#define MONTY_H
#define BUF_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
 * @file: the file read
 * @entry: specify entry either stack or queue
 * @read_len: read number of length
 * @buffer: read store
 */
typedef struct mont_param
{
	unsigned int line_number;
	char **arr;
	int n;
	FILE *file;
	int entry;
	int read_len;
	char buffer[BUF_SIZE];
} param;
void print_error(char *message, char *file);
void add_stack_beg(stack_t **stack, unsigned int);
void add_stack_end(stack_t **stack, unsigned int);
void tokenizer(char *cmd, ssize_t read);
void (*get_dispatch_func(char *str))(stack_t**, unsigned int);
void malloc_error(void);
void pop(stack_t **stack, unsigned int);
void print_int(stack_t **stack, unsigned int line_number);
void print_all(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void print_add(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int);
void print_mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void initialize(void);
void print_line_number(unsigned int line);
void free_stack(stack_t **stack);
void free_array(void);
int is_digit(char *c);
void pall(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int);
void mul(stack_t **stack, unsigned int);
void find_entry(stack_t **stack, unsigned int);
void add_stack_end(stack_t **stack, unsigned int);
void push_stack(stack_t **stack, unsigned int);
void free_everything(stack_t **stack);
void read_file(char *file_name);
void remove_newline(void);
extern param *mont;
#endif
