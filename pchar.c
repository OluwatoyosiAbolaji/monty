#include "monty.h"
/**
  *pcharf - converts the top integer to char
  *@stack: pointer to stacks
  *@line_number: current line number
  *Return: void
  */

void pcharf(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	node = *stack;
	if (!node)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(session.buffer);
		if (*stack)
			free_stack(*stack);
		close(session.file);
		exit(EXIT_FAILURE);
	}
	while (node->next)
		node = node->next;
	if (node->n >= 0 && node->n <= 127)
	{
		printf("%c\n", node->n);
		return;
	}
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	free(session.buffer);
	if (*stack)
		free_stack(*stack);
	close(session.file);
	exit(EXIT_FAILURE);
}
