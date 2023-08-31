#include "monty.h"
/**
  *_mod - calculates the modes of top two integers
  *@stack: pointer to stacks
  *@line_number: current line_number
  *Return: void
  */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;
	stack_t *prev = NULL;
	int mod;

	node = *stack;
	if (!node || session.top < 1)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free(session.buffer);
		if (*stack)
			free_stack(*stack);
		close(session.file);
		exit(EXIT_FAILURE);
	}
	while (node->next)
		node = node->next;
	if (node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(session.buffer);
		if (*stack)
			free_stack(*stack);
		close(session.file);
		exit(EXIT_FAILURE);
	}
	prev = node->prev;
	mod = prev->n % node->n;
	prev->n = mod;
	prev->next = NULL;
	free_stack(node);
}
