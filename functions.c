#include "monty.h"

/**
 * stack_add - Adds the top two elements of the stack.
 * @stack_pointer: Pointer to the stack
 * @num: Current line number
 *
 * Return: void
 */
void stack_add(stack_t **stack_pointer, unsigned int num)
{
	int add;

	if (*stack_pointer == NULL || (*stack_pointer)->next == NULL)
	{
		fprintf(stdout, "L%d: can't add, stack too short\n", num);
		exit(EXIT_FAILURE);
	}

	/* Calculate the sum of the top two elements */
	add = (*stack_pointer)->next->n + (*stack_pointer)->n;

	/* Remove the top element */
	aupop(stack_pointer, num);

	/* Update the new top element with the sum */
	(*stack_pointer)->n = add;
}


/**
 * stack_div - Divides the top two elements of the stack.
 * @stack_pointer: Pointer to the stack
 * @num: Current line number
 *
 * Return: void
 */
void stack_div(stack_t **stack_pointer, unsigned int num)
{
	int division;

	if (*stack_pointer == NULL || (*stack_pointer)->next == NULL)
	{
		fprintf(stdout, "L%d: can't div, stack too short\n", num);
		exit(EXIT_FAILURE);
	}

	if ((*stack_pointer)->n == 0)
	{
		fprintf(stdout, "L%d: division by zero\n", num);
		exit(EXIT_FAILURE);
	}

	/* Calculate the division of the top two elements */
	division = (*stack_pointer)->next->n / (*stack_pointer)->n;

	/* Remove the top element */
	aupop(stack_pointer, num);

	/* Update the new top element with the division result */
	(*stack_pointer)->n = division;
}


/**
 * int_checker - Checks if a string is valid for atoi.
 * @str: The string to check
 *
 * Return: 1 for true, 0 for false
 */
int int_checker(char *str)
{
	int index = 0;

	if (str == NULL)
		return (0);

	if (*str == '-')
		index++;

	while (str[index] != '\0')
	{
		if (!isdigit(str[index]))
			return (0);
		index++;
	}

	return (1);
}



/**
 * stack_mul - Multiplies the top two elements of the stack.
 * @stack_pointer: Pointer to the stack
 * @num: Current line number
 *
 * Return: void
 */
void stack_mul(stack_t **stack_pointer, unsigned int num)
{
	int result;

	if (*stack_pointer == NULL || (*stack_pointer)->next == NULL)
	{
		fprintf(stdout, "L%d: can't mul, stack too short\n", num);
		exit(EXIT_FAILURE);
	}

	/* Perform multiplication of the top two elements */
	result = (*stack_pointer)->next->n * (*stack_pointer)->n;

	/* Remove the top element */
	aupop(stack_pointer, num);

	/* Update the new top element with the multiplication result */
	(*stack_pointer)->n = result;
}



/**
 * stack_sub - Subtracts the top two elements of the stack.
 * @stack_pointer: Pointer to the stack
 * @num: Current line number
 *
 * Return: void
 */
void stack_sub(stack_t **stack_pointer, unsigned int num)
{
	int difference;

	if (*stack_pointer == NULL || (*stack_pointer)->next == NULL)
	{
		fprintf(stdout, "L%d: can't sub, stack too short\n", num);
		exit(EXIT_FAILURE);
	}

	/* Calculate the difference of the top two elements */
	difference = (*stack_pointer)->next->n - (*stack_pointer)->n;

	/* Remove the top element */
	aupop(stack_pointer, num);

	/* Update the new top element with the difference */
	(*stack_pointer)->n = difference;
}
