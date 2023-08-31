#include "monty.h"

/**
  *rotlf - rotates the stacks upwards
  *@stack: pointer to the stacks
  *@line_number: current line_number
  *Return: void
  */

void rotlf(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom = *stack;
	stack_t *new_top;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (bottom->next)
		bottom = bottom->next;
	bottom->next = *stack;
	(*stack)->prev = bottom;
	new_top = bottom->prev;
	new_top->next = NULL;
	bottom->prev = NULL;
}
