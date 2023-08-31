#include "monty.h"
/**
 * pushf - funcion that pushes an element to the stack
 * @stack: A double pointer to the stack (top node of stack)
 * @line_number: line number of input file
 */
void pushf(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	node = *stack;
	if (!node)
	{
		node = malloc(sizeof(stack_t));
		if (node == NULL)
		{
			fprintf(stderr, "Error\n");
			free(session.buffer);
			if (*stack)
				free_stack(*stack);
			close(session.file);
			exit(EXIT_FAILURE);
		}
		node->prev = NULL;
		node->next = *stack;
		if (isint(session.value))
			node->n = atoi(session.value);
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(session.buffer);
			if (*stack)
				free_stack(*stack);
			close(session.file);
			exit(EXIT_FAILURE);
		}
	}
	else if (session.flag == 0)
		add_stack(node, line_number);
	else if (session.flag == 1)
		add_queue(&node, line_number);
	*stack = node;
	(session.top)++;
}

/**
 * add_stack - adds an element to the end of a stack(LIFO)
 * @stack: A double pointer to the stack (top node of stack)
 * @line_number: line number of input file
 */
void add_stack(stack_t *stack, int line_number)
{
	stack_t *new_node = NULL, *node = NULL;
	int i;

	node = stack;
	for (i = 0; node->next; i++)
		node = node->next;
	node->next = malloc(sizeof(stack_t));
	if (node->next == NULL)
	{
		fprintf(stderr, "Error\n");
		free(session.buffer);
		if (stack)
			free_stack(stack);
		close(session.file);
		exit(EXIT_FAILURE);
	}
	new_node = node->next;
	new_node->prev = node;
	new_node->next = NULL;
	if (isint(session.value))
		new_node->n = atoi(session.value);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(session.buffer);
		if (stack)
			free_stack(stack);
		close(session.file);
		exit(EXIT_FAILURE);
	}
}

/**
 * add_queue - adds element to list and sent format of data to a queue (FIFI)
 * @stack: A double pointer to the stack (top node of stack)
 * @line_number: line number of input file
 */
void add_queue(stack_t **stack, int line_number)
{
	stack_t *new_node = NULL;
	stack_t *node = NULL;

	node = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error\n");
		free(session.buffer);
		if (*stack)
			free_stack(*stack);
		close(session.file);
		exit(EXIT_FAILURE);
	}
	new_node->prev = NULL;
	new_node->next = node;
	if (node)
		node->prev = new_node;
	if (isint(session.value))
		new_node->n = atoi(session.value);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(session.buffer);
		if (*stack)
			free_stack(*stack);
		close(session.file);
		exit(EXIT_FAILURE);
	}
	*stack = new_node;
}

/**
 * pallf - prints all values on the stack from the top
 * @stack: A double pointer to the stack (top node of stack)
 * @line_number: line number of input file
 */
void pallf(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *node = NULL;

	(void) line_number;
	node = *stack;
	for (i = 0; node->next; i++)
		node = node->next;
	for (i = 0; node->prev; i++)
	{
		printf("%d\n", node->n);
		node = node->prev;
	}
	printf("%d\n", node->n);
}

/**
 * free_stack - releases the memory occupied by the elements
 * @stack: A double pointer to the stack (top node of stack) to free
 */
void free_stack(stack_t *stack)
{
	stack_t *node;

	while (stack)
	{
		node = stack;
		stack = stack->next;
		free(node);
	}
}
