#ifndef MONTY_H
#define MONTY_H

#define BUFFSIZE 4096
/** headers **/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>


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
  *struct session_t - all data structures needed throughout an execution
  *@buffer: string buffer
  *@file: file to be opened
  *@flag : flag for stack-queue switch
  *@top: index of top stack
  *@value: number to be processed
  */

typedef struct session_t
{
	char *buffer;
	int file;
	int flag;
	int top;
	char *value;
} session_t;


/** Functions **/
void execute(char *buffer);
int isint(char *string);
void pushf(stack_t **stack, unsigned int line_number);
void add_stack(stack_t *node, int line_number);
void add_queue(stack_t **node, int line_number);
void pallf(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void popf(stack_t **stack, unsigned int line_number);
void pintf(stack_t **stack, unsigned int line_number);
void addf(stack_t **stack, unsigned int line_number);
void swapf(stack_t **stack, unsigned int line_number);
void nopf(stack_t **stack, unsigned int line_nnumber);
void subf(stack_t **stack, unsigned int line_nnumber);
void pstrf(stack_t **stack, unsigned int line_number);
void divf(stack_t **stack, unsigned int line_number);
void mulf(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void pcharf(stack_t **stack, unsigned int line_number);
void rotlf(stack_t **stack, unsigned int line_number);
void rotrf(stack_t **stack, unsigned int line_number);
void stackf(stack_t **stack, unsigned int line_number);
void queuef(stack_t **stack, unsigned int line_number);
void function(stack_t **stack, int linenumber, char *instruction);

/** global variables **/
extern session_t session;
#endif
