#include "monty.h"
/**
  *pstrf - prints a string from the top integers
  *@stack: pointer to stacks
  *@line_number: current line_number
  *Return: void
  */

void pstrf(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	(void)line_number;
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	while (node->next)
		node = node->next;
	while (node)
	{
		if (node->n >= 0 && node->n <= 127)
		{
			if (node->n == 0)
			{
				putchar('\n');
				break;
			}
			putchar(node->n);
		}
		else
			break;
		node = node->prev;
	}
}
