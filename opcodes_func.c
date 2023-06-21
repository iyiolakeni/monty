#include "monty.h"

/**
 * aupush - Pushes an element to the stack.
 * @stack_pointer: Pointer to the stack
 * @num: Current line number
 *
 * Return: void
 */
void aupush(stack_t **stack_pointer, unsigned int num)
{
	stack_t *new_node, *temp;
	char *push_argument = strtok(NULL, "\n \t");
	int push_value;

	/* If push, tests if the push_argument was valid or not */
	if (!int_checker(push_argument))
	{
		fprintf(stdout, "L%u: usage: push integer\n", num);
		exit(EXIT_FAILURE);
	}

	push_value = atoi(push_argument);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = push_value;
	new_node->prev = NULL;
	new_node->next = NULL;

	/* Checks if stack is empty */
	if ((*stack_pointer) == NULL)
		*stack_pointer = new_node;
	else if (SQ)
	{
		/* Puts new node on top if not empty */
		(*stack_pointer)->prev = new_node;
		new_node->next = *stack_pointer;
		*stack_pointer = new_node;
	}
	else
	{
		/* Puts new node on the bottom */
		temp = *stack_pointer;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
}



/**
 * aupall - Prints all values on the stack, starting from the top of the stack.
 * @stack_pointer: Pointer to the stack
 * @num: Current line number (unused)
 *
 * Return: void
 */
void aupall(stack_t **stack_pointer, unsigned int num)
{
	stack_t *current_node;

	UNUSED(num);

	current_node = *stack_pointer;
	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}


/**
 * aupint - prints the value at the top of the stack, followed by a new line.
 * @stack_pointer: the stack
 * @num: the current line number
 *
 * Return: void
 */
void aupint(stack_t **stack_pointer, unsigned int num)
{
	if (*stack_pointer == NULL)
	{
		fprintf(stdout, "L%d: can't pint, stack empty\n", num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_pointer)->n);
}


/**
 * aupop - Removes the top element of the stack.
 * @stack_pointer: Pointer to the stack
 * @num: Current line number
 *
 * Return: void
 */
void aupop(stack_t **stack_pointer, unsigned int num)
{
	stack_t *temp;

	if (*stack_pointer == NULL)
	{
		fprintf(stdout, "L%d: can't pop an empty stack\n", num);
		exit(EXIT_FAILURE);
	}

	temp = *stack_pointer;
	*stack_pointer = (*stack_pointer)->next;
	free(temp);
}


/**
 * auswap - Swaps the top two elements of the stack.
 * @stack_pointer: Pointer to the stack
 * @num: Current line number
 *
 * Return: void
 */
void swap(stack_t **stack_pointer, unsigned int num)
{
	int temp;

	if (*stack_pointer == NULL || (*stack_pointer)->next == NULL)
	{
		fprintf(stdout, "L%d: can't swap, stack too short\n", num);
		exit(EXIT_FAILURE);
	}

	temp = (*stack_pointer)->n;
	(*stack_pointer)->n = (*stack_pointer)->next->n;
	(*stack_pointer)->next->n = temp;
}
