#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct stack_node {
    int value;
    struct stack_node *next;
} stack_node_t;

stack_node_t *push(stack_node_t *top, int value);
void pall(stack_node_t *top);
void pint(stack_node_t *top, int line_number);
void swap(stack_node_t **top, int line_number);
void add(stack_node_t **top, int line_number);
void nop(void);
void free_stack(stack_node_t *top);
int is_integer(const char *str);
void usage_error(void);
void file_open_error(const char *filename);
void unknown_instruction_error(int line_number, const char *opcode);
void malloc_error(void);

#endif /* MONTY_H */

