#include <stdio.h>
#include "pile.h"

int main(int argc, char const *argv[])
{
	Stack stack = new_stack();

	// Adding 3 then 7.
	stack = push(stack, 3);
	stack = push(stack, 5);
	stack = push(stack, 7);
	print_stack(stack);

	// Getting top
	printf("The top of the stack is : %d.\n", get_top(stack));

	// Removing 7
	stack = pop(stack);
	print_stack(stack);

	// Destroying stack
	stack = destroy_stack(stack);
	print_stack(stack);

	return 0;
}