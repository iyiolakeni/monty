#include "monty.h"

int SQ = 1;

/**
 * main - Entry point of the Monty program.
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: Exit code
 */
int main(int argc, char **argv)
{
	FILE *file_in;
	unsigned int line_number = 0;
	char *line = NULL;
	stack_t *top = NULL;
	instruction_t *instruction = NULL;
	size_t glsize = 0;

	/* Check for proper number of arguments */
	if (argc != 2)
	{
		fprintf(stdout, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open file */
	file_in = fopen(argv[1], "r");
	if (file_in == NULL)
	{
		fprintf(stdout, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Parse file line by line */
	while (getline(&line, &glsize, file_in) != -1)
	{
		line_number++;
		instruction = auparser(line);

		/* Skip if the line is empty or a comment */
		if (!(instruction->opcode) || instruction->opcode[0] == '#')
		{
			free(instruction);
			if (line)
				free(line);
			line = NULL;
			continue;
		}

		/* Execute the instruction */
		if (instruction->f)
			instruction->f(&top, line_number);
		else
		{
			fprintf(stdout, "L%d: unknown instruction %s\n",
				line_number, instruction->opcode);
			if (line)
				free(line);
			if (top)
				free_stack(top);
			free(instruction);
			fclose(file_in);
			exit(EXIT_FAILURE);
		}

		/* Free memory and prepare for the next line */
		if (line)
			free(line);
		line = NULL;
		free(instruction);
	}

	/* Free memory and close file */
	if (line)
		free(line);
	free_stack(top);
	fclose(file_in);
	return (0);
}
