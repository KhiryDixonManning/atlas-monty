#include "monty.h"

FILE *file = NULL;

/**
 * main - Hi Mr. Monty how are you?
 * @argc: The ticker for the arguments who come in
 * @argv: The arguments themselves and what they are worth
 * Return: Sometimes 0 (on Success).
 */
int main(int argc, char **argv)
{
    void (*f)(stack_t **, unsigned int) = NULL;
    char *buffer = NULL, op[50] = {'\0'}, pushNum[50] = {'\0'}, *token = NULL;
    size_t bufsize = 0;
    stack_t *stack = NULL;
    unsigned int line_number = 1;

    if (argc != 2)
        usage_error();

    file = fopen(argv[1], "r");
    if (!file)
        file_open_error(argv[1]);

    while (getline(&buffer, &bufsize, file) != -1)
    {
        token = strtok(buffer, " \t\n");
        if (!token)
        {
            line_number++;
            continue;
        }

        strcpy(op, token);
        f = get_func(&stack, line_number, op);
        if (!f)
        {
            free(buffer);
            free_stack(stack);
            fclose(file);
            malloc_error();
        }

        if (strcmp(op, "push") == 0)
        {
            token = strtok(NULL, " \t\n");
            if (!token || !is_integer(token))
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                free(buffer);
                free_stack(stack);
                fclose(file);
                exit(EXIT_FAILURE);
            }
            int value = atoi(token);
            stack = push(stack, value);
        }
        else
        {
            f(&stack, line_number);
        }

        line_number++;
    }

    free(buffer);
    free_stack(stack);
    fclose(file);
    return 0;
}

