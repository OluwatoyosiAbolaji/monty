#include "monty.h"
/**
 * pintf - prints the value at the top of the stack
 * @stack: A double pointer to the stack (top node of stack)
 * @line_number: line number of input file
 */
void pintf(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	node = *stack;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		free(session.buffer);
		if (*stack)
			free_stack(*stack);
		close(session.file);
		exit(EXIT_FAILURE);
	}
	while (node->next)
		node = node->next;
	printf("%d\n", (node)->n);
}
