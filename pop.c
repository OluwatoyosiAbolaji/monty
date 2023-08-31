#include "monty.h"
/**
 * popf - removes top element from stack
 * @stack: A double pointer to the stack (top node of stack)
 * @line_number: line number of input file
 */
void popf(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	stack_t *prev;

	node = *stack;
	prev = NULL;
	if (!node)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(session.buffer);
		if (*stack)
			free_stack(*stack);
		close(session.file);
		exit(EXIT_FAILURE);
	}
	while (node->next)
		node = node->next;
	prev = node->prev;
	printf("%d\n", node->n);
	free_stack(node);
	prev->next = NULL;
	(session.top)--;
}
