#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @top: The top of the stack.
 * @value: The value to push.
 * Return: The new top of the stack.
 */
stack_node_t *push(stack_node_t *top, int value)
{
	stack_node_t *new_node = malloc(sizeof(stack_node_t));

	if (new_node == NULL)
	{
		malloc_error();
	}
	new_node->value = value;
	new_node->next = top;
	return (new_node);
}

/**
 * pall - Prints all values on the stack, starting from the top.
 * @top: The top of the stack.
 */
void pall(stack_node_t *top)
{
	stack_node_t *current = top;

	while (current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

/**
 * pint - Prints the value at the top of the stack.
 * @top: The top of the stack.
 * @line_number: The current line number in the file.
 */
void pint(stack_node_t *top, int line_number)
{
	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top->value);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @top: The top of the stack.
 * @line_number: The current line number in the file.
 */
void swap(stack_node_t **top, int line_number)
{
	stack_node_t *first, *second;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*top = second;
}

/**
 * add - Adds the top two elements of the stack.
 * @top: The top of the stack.
 * @line_number: The current line number in the file.
 */
void add(stack_node_t **top, int line_number)
{
	stack_node_t *first, *second;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *top;
	second = first->next;
	second->value += first->value;
	*top = second;
	free(first);
}

/**
 * nop - Does nothing.
 */
void nop(void)
{
	/* Do nothing */
}

/**
 * free_stack - Frees the stack.
 * @top: The top of the stack.
 */
void free_stack(stack_node_t *top)
{
	stack_node_t *next;

	while (top != NULL)
	{
		next = top->next;
		free(top);
		top = next;
	}
}

/**
 * is_integer - Checks if a string is an integer.
 * @str: The string to check.
 * Return: 1 if the string is an integer, 0 otherwise.
 */
int is_integer(const char *str)
{
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	if (!*str)
	{
		return (0);
	}
	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/**
 * usage_error - Prints usage error and exits.
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * file_open_error - Prints file open error and exits.
 * @filename: The name of the file that could not be opened.
 */
void file_open_error(const char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * unknown_instruction_error - Prints unknown instruction error and exits.
 * @line_number: The line number where the error occurred.
 * @opcode: The unknown opcode.
 */
void unknown_instruction_error(int line_number, const char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - Prints malloc error and exits.
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * get_func - Gets the function corresponding to the opcode.
 * @stack: The stack.
 * @line_number: The current line number in the file.
 * @op: The opcode.
 * Return: The function corresponding to the opcode.
 */
void (*get_func(stack_t **stack, unsigned int line_number, char *op))(stack_t **, unsigned int)
{
	if (strcmp(op, "pall") == 0)
	{
		return ((void (*)(stack_t **, unsigned int)) pall);
	}
	else if (strcmp(op, "pint") == 0)
	{
		return ((void (*)(stack_t **, unsigned int)) pint);
	}
	else if (strcmp(op, "swap") == 0)
	{
		return ((void (*)(stack_t **, unsigned int)) swap);
	}
	else if (strcmp(op, "add") == 0)
	{
		return ((void (*)(stack_t **, unsigned int)) add);
	}
	else if (strcmp(op, "nop") == 0)
	{
		return ((void (*)(stack_t **, unsigned int)) nop);
	}
	else
	{
		unknown_instruction_error(line_number, op);
		return (NULL);  /* To avoid compiler warning */
	}
}
