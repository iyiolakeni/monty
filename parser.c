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
		if (strcmp(instruction->opcode, "pall") == 0)
			instruction->f = aupall;
		if (strcmp(instruction->opcode, "pint") == 0)
			instruction->f = aupint;
		if (strcmp(instruction->opcode, "pop") == 0)
			instruction->f = aupop;
		if (strcmp(instruction->opcode, "swap") == 0)
			instruction->f = auswap;
		if (strcmp(instruction->opcode, "add") == 0)
			instruction->f = stack_add;
		if (strcmp(instruction->opcode, "nop") == 0)
			instruction->f = aunop;
		if (strcmp(instruction->opcode, "sub") == 0)
			instruction->f = stack_sub;
		if (strcmp(instruction->opcode, "div") == 0)
			instruction->f = stack_div;
		if (strcmp(instruction->opcode, "mul") == 0)
			instruction->f = stack_mul;
		if (strcmp(instruction->opcode, "mod") == 0)
			instruction->f = aumod;
		if (strcmp(instruction->opcode, "pchar") == 0)
			instruction->f = aupchar;
		if (strcmp(instruction->opcode, "pstr") == 0)
			instruction->f = aupstr;
		if (strcmp(instruction->opcode, "rotl") == 0)
			instruction->f = aurotl;
		if (strcmp(instruction->opcode, "rotr") == 0)
			instruction->f = aurotr;
		if (strcmp(instruction->opcode, "stack") == 0)
			instruction->f = austack;
		if (strcmp(instruction->opcode, "queue") == 0)
			instruction->f = auqueue;
	}

	return (instruction);
}
