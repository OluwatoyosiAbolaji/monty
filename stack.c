#include "monty.h"
/**
  *stackf - handles stacks
  *@stack: pointer to the stacks
  *@line_number: current line_number
  *Return: void
  */

void stackf(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	session.flag = 0;
}

/**
  *queuef - handles queues
  *@stack: pointer to the stacks
  *@line_number: current_line_number
  *Return: void
  */

void queuef(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	session.flag = 1;
}
