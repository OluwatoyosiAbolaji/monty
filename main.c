#include "monty.h"
session_t session = {NULL, 0, 0, -1, NULL};
/**
  *main - entry point of the program
  *@argc: number of arguments passed
  *@argv: argument vector
  *Return: 0 on success, exits with EXIT_FAILURE on failure
  */

int main(int argc, char **argv)
{
	int file, read_file;
	char *buffer = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(sizeof(char) * BUFFSIZE);
	if (!buffer)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	read_file = read(file, buffer, BUFFSIZE);
	if (read_file < 0)
	{
		fprintf(stderr, "Error: can't read file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer[read_file] = '\0';
	execute(buffer);
	free(buffer);
	close(file);
	return (0);
}

/**
  *execute - executes a line of instruction
  *@buffer: line buffer of instructions
  *Return: void
  */

void execute(char *buffer)
{
	char *instruction = NULL, *line = NULL, *buf = buffer;
	int i = 0, linenumber = 0;
	char *argument = NULL;
	stack_t *stack = NULL;

	line = strtok(buf, "\n");
	linenumber++;
	while (line)
	{
		buf = buf + strlen(line) + 1;
		argument = strtok(line, " \t");
		while (argument && i < 2)
		{
			if (!i)
				instruction = argument;
			else
				session.value = argument;
			i++;
			argument = strtok(NULL, " \t");
		}
		if (instruction[0] == '#' && instruction)
		{
			line = strtok(buf, "\n");
			linenumber++;
			i = 0;
			continue;
		}
		function(&stack, linenumber, instruction);
		linenumber++;
		session.value = NULL;
		i = 0;
		line = strtok(buf, "\n");
	}
	if (stack)
		free_stack(stack);
}

/**
  *function - applies the relevant function to the instruction
  *@stack: pointer to stacks
  *@linenumber: current linenumber
  *@instruction: instruction to be executed
  *Return: void
  */

void function(stack_t **stack, int linenumber, char *instruction)
{
	int i;
	instruction_t executables[] = {
		{"push", pushf},
		{"pall", pallf},
		{"pint", pintf},
		{"pop", popf},
		{"swap", swapf},
		{"add", addf},
		{"nop", nopf},
		{"sub", subf},
		{"pstr", pstrf},
		{"mul", mulf},
		{"div", divf},
		{"mod", _mod},
		{"pchar", pcharf},
		{"rotl", rotlf},
		{"rotr", rotrf},
		{"stack", stackf},
		{"queue", queuef},
		{NULL, NULL}
	};

	for (i = 0; executables[i].opcode; i++)
	{
		if (strcmp(instruction, executables[i].opcode) == 0)
		{
			executables[i].f(stack, linenumber);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", linenumber, instruction);
	free(session.buffer);
	if (*stack)
		free_stack(*stack);
	close(session.file);
	exit(EXIT_FAILURE);
}
