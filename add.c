#include "monty.h"
/**
 * addf - adds the 2 top elements of stack
 * @stack: A double pointer to the stack (top node of stack)
 * @line_number: line number of input file
 */
void addf(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;
	stack_t *prev = NULL;
	int sum;

	node = *stack;
	if (!node || session.top < 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(session.buffer);
		if (*stack)
			free_stack(*stack);
		close(session.file);
		exit(EXIT_FAILURE);
	}
	while (node->next)
		node = node->next;
	prev = node->prev;
	sum = node->n + prev->n;
	prev->n = sum;
	prev->next = NULL;
	free_stack(node);
}
