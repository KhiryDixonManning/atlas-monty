              
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
                fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
        file = fopen(argv[1], "r");
        if (!file)
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
        for (; getline(&buffer, &bufsize, file) != EOF; line_number++)
        {
                token = strtok((buffer), " \t\n");
                if (!token)
                {
                        free(buffer), buffer = NULL;
                        continue;
                }
                strcpy(op, token);
                f = get_func(&stack, line_number, op);
                if (!f)
                        fprintf(stderr, "Error: malloc failed\n"), error();
                if (strcmp(op, "push") == 0)
                {
                        token = strtok(NULL, " \t\n");
        exit(EXIT_FAILURE);or();ck(stack);%d: usage: push integer\n", line_number);number), error();
