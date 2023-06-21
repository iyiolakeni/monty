#include "monty.h"

/**
 * aurotl - Rotates the stack to the left.
 * @stack_pointer: Pointer to the stack
 * @num: Current line number
 *
 * Return: void
 */
void aurotl(stack_t **stack_pointer, unsigned int num)
{
	stack_t *current;
	int first_value;

	/* Unused parameter */
	UNUSED(num);

	current = *stack_pointer;

	if (current)
	{
		first_value = current->n;

		while (current != NULL)
		{
			if (current->next)
				current->n = current->next->n;
			else
				current->n = first_value;

			current = current->next;
		}
	}
}


/**
 * aurotr - Rotates the stack to the right.
 * @stack_pointer: Pointer to the stack
 * @num: Current line number
 *
 * Return: void
 */
void aurotr(stack_t **stack_pointer, unsigned int num)
{
	stack_t *current, *last_node;
	int last_value;

	/* Unused parameter */
	UNUSED(num);

	if ((*stack_pointer) != NULL)
	{
		current = *stack_pointer;

		/* Find the last node in the stack */
		for (; current->next != NULL; current = current->next)
		{
			/* No operations needed here */
		}

		last_value = current->n;

		/* Shift the values to the right */
		for (; current->prev != NULL; current = current->prev)
		{
			current->n = current->prev->n;
		}

		current->n = last_value;
	}
}
