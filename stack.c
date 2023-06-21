#include "monty.h"

/**
 * austack - changes to LIFO
 * @stack_pointer: monty stack
 * @num: line number of file
 */
void austack(stack_t **stack_pointer, unsigned int num)
{
	UNUSED(stack_pointer);
	UNUSED(num);
	SQ = 1;
}


/**
 * auqueue - changes to FIFO
 * @stack_pointer: monty stack
 * @num: line number of file
 */
void auqueue(stack_t **stack_pointer, unsigned int num)
{
	UNUSED(stack_pointer);
	UNUSED(num);
	SQ = 0;
}
