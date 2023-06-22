#include "monty.h"

/**
 * free_stack - frees a stack_t list.
 * @head: a pointer to the head
 *
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *next;

	if (!head)
		return;

	/**
	 * Iterate through the stack nodes using a for loop
	 * The initialization is performed before entering the loop
	 * The condition is checked before each iteration
	 * The iteration is performed at the end of each iteration
	 */
	for (; head != NULL; head = next)
	{
		/* Store the next node in the "next" pointer */
		next = head->next;

		/* Free the current node */
		free(head);
	}
}


/**
 * get_opcode - gets the opcode and sets push_arg if it's push
 * @string: the line of code
 *
 * Return: the opcode
*/
char *get_opcode(char *string)
{
	char *opcode;

	/**
	 * Use strtok function to extract the first
	 * argument (opcode) from the input string
	 * The delimiter "\n\t " is used to separate
	 * the opcode from the rest of the string
	 */

	opcode = strtok(string, "\n\t ");
	/*Return the extracted opcode*/
	return (opcode);
}
