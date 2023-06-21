#include "monty.h"

/**
 * aunop - The opcode nop doesn’t do anything.
 * @stack_pointer: Pointer to the stack (unused)
 * @num: Current line number (unused)
 *
 * Return: void
 */
void aunop(stack_t **stack_pointer, unsigned int num)
{
	/* Unused parameters */
	(void)stack_pointer;
	(void)num;
}


/**
 * aumod - Performs modulus operation on the top two elements of the stack.
 * @stack_pointer: Pointer to the stack
 * @num: Current line number
 *
 * Return: void
 */
void aumod(stack_t **stack_pointer, unsigned int num)
{
	int result;

	if (*stack_pointer == NULL || (*stack_pointer)->next == NULL)
	{
		fprintf(stdout, "L%d: can't mod, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	if ((*stack_pointer)->n == 0)
	{
		fprintf(stdout, "L%d: division by zero\n", num);
		exit(EXIT_FAILURE);
	}

	result = (*stack_pointer)->next->n % (*stack_pointer)->n;
	aupop(stack_pointer, num);
	(*stack_pointer)->n = result;
}
