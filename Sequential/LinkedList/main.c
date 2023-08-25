#include <stdio.h>
#include "linked_list.h"

int main(int argc, char const *argv[])
{
	// Create a new ll (linked_list)
	LinkedList ll = create_linked_list();

	// Add some valuess
	ll = push_head(ll, 3);
	ll = push_tail(ll, 5);
	ll = push_head(ll, 7);
	ll = push_tail(ll, 9);
	print_list(ll); // Has to be : 7 3 5 9

	// Remove some values
	ll = pop_head(ll);
	ll = pop_tail(ll);
	print_list(ll); // Has to be : 3 5

	// Get length
	printf("List has length : %d", length(ll));

	// Destroy the list
	ll = destroy_list(ll);
	
	return 0;
}