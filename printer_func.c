#include "monty.h"

/**
 * aupchar - Prints the character at the top of the stack.
 * @stack_pointer: Pointer to the stack
 * @num: Current line number
 *
 * Return: void
 */
void aupchar(stack_t **stack_pointer, unsigned int num)
{
	/* Check if stack is empty */
	if (*stack_pointer == NULL)
	{
		fprintf(stdout, "L%d: can't pchar, stack empty\n", num);
		exit(EXIT_FAILURE);
	}

	/* Check if the value is a printable character */
	if (!isprint((*stack_pointer)->n))
	{
		fprintf(stdout, "L%d: can't pchar, value out of range\n", num);
		exit(EXIT_FAILURE);
	}

	/* Print the character */
	fprintf(stdout, "%c\n", (*stack_pointer)->n);
}


/**
 * aupstr - Prints the string represented by the stack.
 * @stack_pointer: Pointer to the stack
 * @num: Current line number
 *
 * Return: void
 */
void aupstr(stack_t **stack_pointer, unsigned int num)
{
	stack_t *temp;

	/* Create a temporary pointer to traverse the stack */
	temp = *stack_pointer;

	/* Unused parameter */
	UNUSED(num);

	/* Iterate through the stack and print the characters */
	while (temp != NULL && temp->n != 0 && isprint(temp->n))
	{
		printf("%c", tmp->n);
		temp = temp->next;
	}

	/* Print a new line at the end */
	printf("\n");
}
