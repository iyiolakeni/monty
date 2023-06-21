#include "monty.h"

/**
 * auparser - Parses a line and returns the corresponding instruction.
 * @line: The line to parse
 *
 * Return: A pointer to the proper instruction
 */
instruction_t *auparser(char *line)
{
	char *opcode;
	instruction_t *instruction;

	opcode = get_opcode(line);
	instruction = malloc(sizeof(*instruction));
	if (instruction == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	instruction->opcode = opcode;
	instruction->f = NULL;

	/* Set the function pointer based on the opcode */

	if (instruction->opcode)
	{
		if (strcmp(instruction->opcode, "push") == 0)
			instruction->f = aupush;
		else if (strcmp(instruction->opcode, "pall") == 0)
			instruction->f = aupall;
		else if (strcmp(instruction->opcode, "pint") == 0)
			instruction->f = aupint;
		else if (strcmp(instruction->opcode, "pop") == 0)
			instruction->f = aupop;
		else if (strcmp(instruction->opcode, "swap") == 0)
			instruction->f = auswap;
		else if (strcmp(instruction->opcode, "add") == 0)
			instruction->f = stack_add;
		else if (strcmp(instruction->opcode, "nop") == 0)
			instruction->f = aunop;
		else if (strcmp(instruction->opcode, "sub") == 0)
			instruction->f = stack_sub;
		else if (strcmp(instruction->opcode, "div") == 0)
			instruction->f = stack_div;
		else if (strcmp(instruction->opcode, "mul") == 0)
			instruction->f = stack_mul;
		else if (strcmp(instruction->opcode, "mod") == 0)
			instruction->f = aumod;
		else if (strcmp(instruction->opcode, "pchar") == 0)
			instruction->f = aupchar;
		else if (strcmp(instruction->opcode, "pstr") == 0)
			instruction->f = aupstr;
		else if (strcmp(instruction->opcode, "rotl") == 0)
			instruction->f = aurotl;
		else if (strcmp(instruction->opcode, "rotr") == 0)
			instruction->f = aurotr;
		else if (strcmp(instruction->opcode, "stack") == 0)
			instruction->f = austack;
		else if (strcmp(instruction->opcode, "queue") == 0)
			instruction->f = auqueue;
	}

	return (instruction);
}
