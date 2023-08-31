#include "monty.h"

/**
  *isint - checks if string is an integer
  *@string: string to be checked
  *Return: 1 on success, 0 on failure
  */

int isint(char *string)
{
	int i = 0;

	if (!string)
		return (0);
	if (string[i] == '-')
		i++;
	while (string[i])
	{
		if (!(isdigit(string[i])))
			return (0);
		i++;
	}
	return (1);
}
