#include "monty.h"
/**
 * divf - divides the second top element of the stack by the top element
 * @stack: A double pointer to the stack (top node of stack)
 * @line_number: line number of input file
 */
void divf(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;
	stack_t *prev = NULL;
	int div;

	node = *stack;
	if (!node || session.top < 1)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	div = prev->n / node->n;
	prev->n = div;
	prev->next = NULL;
	free_stack(node);
}
