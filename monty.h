#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define UNUSED(x) (void)(x)
#define LINE_MAX 1024

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int SQ;

/*OPcodes Functions*/
void aupush(stack_t **stack_pointer, unsigned int num);
void aupall(stack_t **stack_pointer, unsigned int num);
void aupint(stack_t **stack_pointer, unsigned int num);
void aupop(stack_t **stack_pointer, unsigned int num);
void auswap(stack_t **stack_pointer, unsigned int num);

/* OPcodes Functions*/
void aunop(stack_t **stack_pointer, unsigned int num);
void aumod(stack_t **stack_pointer, unsigned int num);

/* Functions.c*/
void stack_add(stack_t **stack_pointer, unsigned int num);
void stack_div(stack_t **stack_pointer, unsigned int num);
int int_checker(char *str);
void stack_mul(stack_t **stack_pointer, unsigned int num);
void stack_sub(stack_t **stack_pointer, unsigned int num);

/*Printer Function*/
void aupchar(stack_t **stack_pointer, unsigned int num);
void aupstr(stack_t **stack_pointer, unsigned int num);

/*Rotate Function*/
void aurotl(stack_t **stack_pointer, unsigned int num);
void aurotr(stack_t **stack_pointer, unsigned int num);

/* Stack functions*/
void austack(stack_t **stack_pointer, unsigned int num);
void auqueue(stack_t **stack_pointer, unsigned int num);

/*Parser*/
instruction_t *auparser(char *line);

/* Stack Function */
void free_stack(stack_t *head);
char *get_opcode(char *string);

#endif
