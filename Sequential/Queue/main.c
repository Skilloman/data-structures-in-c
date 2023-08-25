#include <stdio.h>
#include "queue.h"

// You can remove debug in the file 'queue.c'

int main(void)
{
	// Create a new queue.
	Queue queue = new_queue(); 

	// Add to values
	queue = enqueue(queue, 3);
	queue = enqueue(queue, 5);
	queue = enqueue(queue, 7);
	queue = enqueue(queue, 9);
	print_queue(queue);

	// Remove the first added element
	queue = dequeue(queue);
	print_queue(queue);

	// Get the back and the front
	printf("[i] Back value : %d\n", get_back(queue));
	printf("[i] Front value : %d\n", get_front(queue));

	// Get length
	printf("[i] Queue's length : %d\n", length(queue));

	// Destroy the queue
	queue = clear_queue(queue);

	return 0;
}
