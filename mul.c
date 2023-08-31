#include "monty.h"
/**
  *mulf - multiplies the top two integers
  *@stack: pointer to stacks
  *@line_number: current line number
  *Return: void
  */

void mulf(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;
	stack_t *prev = NULL;
	int mul;

	node = *stack;
	if (!node || session.top < 1)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(session.buffer);
		if (*stack)
			free_stack(*stack);
		close(session.file);
		exit(EXIT_FAILURE);
	}
	while (node->next)
		node = node->next;
	prev = node->prev;
	mul = prev->n * node->n;
	prev->n = mul;
	prev->next = NULL;
	free_stack(node);
}
