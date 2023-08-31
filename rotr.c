#include "monty.h"
/**
  *rotrf - rotates the stacks downwards
  *@stack: pointer to the stack
  *@line_number: current line number
  *Return: void
  */

void rotrf(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom = *stack;
	stack_t *new_bottom;
	stack_t *top = *stack;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (top->next)
		top = top->next;
	new_bottom = bottom->next;
	new_bottom->prev = NULL;
	top->next = bottom;
	bottom->next = NULL;
	bottom->prev = top;
}
