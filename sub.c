#include "monty.h"
/**
 * subf - subtracts the 2 top elements of stack (top from second top)
 * @stack: A double pointer to the stack (top node of stack)
 * @line_number: line number of input file
 */
void subf(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;
	stack_t *prev = NULL;
	int sub;

	node = *stack;
	if (!node || session.top < 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free(session.buffer);
		if (*stack)
			free_stack(*stack);
		close(session.file);
		exit(EXIT_FAILURE);
	}
	while (node->next)
		node = node->next;
	prev = node->prev;
	sub = prev->n - node->n;
	prev->n = sub;
	prev->next = NULL;
	free_stack(node);
}
