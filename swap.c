#include "monty.h"
/**
 * swapf - swaps the top 2 elements of stack
 * @stack: A double pointer to the stack (top node of stack)
 * @line_number: line number of input file
 */
void swapf(stack_t **stack, unsigned int line_number)
{
	stack_t *tnode;
	int number;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(session.buffer);
		if (*stack)
			free_stack(*stack);
		close(session.file);
		exit(EXIT_FAILURE);
	}
	tnode = *stack;
	while (tnode->next)
		tnode = tnode->next;
	number = tnode->n;
	tnode->n = (tnode->prev)->n;
	(tnode->prev)->n = number;
}
