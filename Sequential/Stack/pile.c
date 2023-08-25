#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

Stack new_stack(void){
	printf("[i] A new stack is created\n");
	return NULL;
}

Stack push(Stack st, DataType value)
{
	Stack st_elem = malloc(sizeof(Stack));

	if(st_elem == NULL)
	{
		fprintf(stderr, "[!] Dynamic allocation error.\n");
		exit(1);
	}

	st_elem->value = value;
	st_elem->next_element = st;

	printf("[i] The element %d has been pushed\n", value);
	return st_elem;
}

Stack pop(Stack st)
{
	if(is_empty(st))
	{
		fprintf(stderr, "[!] Unable to pop, the stack is empty\n");
		return st;
	}

	printf("[i] The element %d has been poped\n", st->value);
	Stack new_st = st->next_element;
	free(st);

	return new_st;
}

DataType get_top(Stack st)
{
	if(is_empty(st))
	{
		fprintf(stderr, "[!] Top doesn't exist on an empty stack.\n");
		exit(EXIT_FAILURE);
	}

	return st->value;
}

void print_stack(Stack st)
{
	if (st == NULL)
	{
		fprintf(stderr, "[!] Stack is empty, nothing to print.\n");
		return;
	}

	printf("[i] Stack values :\n");
	while (st != NULL)
	{
		printf("\t| %d |\n", st->value);
		st = st->next_element;
	}
}

int is_empty(Stack st)
{
	return NULL == st;
}

Stack destroy_stack(Stack st)
{
	while(st != NULL)
		st = pop(st);

	printf("[i] The stack has been destroyed\n");
	return st;
}