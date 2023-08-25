#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define DEBUG 1

Queue new_queue(void)
{
	DEBUG == 1 ? printf("[i] A new queue has been created.\n") : printf("");
	return NULL;
}

Queue enqueue(Queue queue, DataType value)
{
	// In every case, we have to create a cell
	Cell *pt_cell = calloc(1, sizeof(Cell*));

	if(pt_cell == NULL)
	{
		DEBUG == 1 ? fprintf(stderr, "[!] Dynamic allocation error.\n") : printf("");
		exit(EXIT_FAILURE);
	}

	pt_cell->value = value;
	pt_cell->next_cell = NULL;
	
	// But if there it's not an empty queue, point on the queue
	if(!is_empty(queue))
		pt_cell->next_cell = queue;

	DEBUG == 1 ? printf("[i] The element %d has been enqueued.\n", value) : printf("");
		
	return pt_cell;
}

Queue dequeue(Queue queue)
{
	if(is_empty(queue))
	{
		DEBUG == 1 ? fprintf(stderr, "[!] Empty queue, can't dequeue.\n") : printf("");
		return queue;
	}

	if(length(queue) == 1)
	{
		free(queue);
		queue = NULL;

		return NULL;
	}

	Cell *pt_last_cell = queue->next_cell;
	Cell *pt_before_last_cell = queue;

	while(pt_last_cell->next_cell != NULL)
	{
		pt_last_cell = pt_last_cell->next_cell;
		pt_before_last_cell = pt_before_last_cell->next_cell;
	}

	DataType in_order_to_print = pt_last_cell->value;
	pt_before_last_cell->next_cell = NULL;
	
	free(pt_last_cell);
	pt_last_cell = NULL;

	DEBUG == 1 ? printf("[i] The element %d has been dequeued.\n", in_order_to_print) : printf("");

	return queue;

}

int is_empty(Queue queue)
{
	return NULL == queue ? 1 : 0;
}

int length(Queue queue)
{
	int length = 0;

	while(queue != NULL)
	{
		queue = queue->next_cell;
		length++;
	}

	return length;
}

DataType get_back(Queue queue)
{
	if(is_empty(queue))
	{
		DEBUG == 1 ? fprintf(stderr, "[!] Empty queue, impossible to get the back.\n") : printf("");
		exit(EXIT_FAILURE);
	}

	return queue->value;
}

DataType get_front(Queue queue)
{
	if(is_empty(queue))
	{
		DEBUG == 1 ? fprintf(stderr, "[!] Empty queue, impossible to get the front.\n") : printf("");
		exit(EXIT_FAILURE);
	}

	while(queue->next_cell != NULL)
		queue = queue->next_cell;

	return queue->value;
}

void print_queue(Queue queue)
{
	if(is_empty(queue))
	{
		DEBUG == 1 ? fprintf(stderr, "[!] Empty, nothing to print.\n") : printf("");
		return;
	}
	DEBUG == 1 ? printf("[i] Queue values : \n") : printf("");
	while(queue != NULL)
	{
		queue->next_cell != NULL 
			? printf("%d -> ", queue->value) 
			: printf("%d\n", queue->value);

		queue = queue->next_cell;
	}
}

Queue clear_queue(Queue queue)
{
	while(queue != NULL)
		queue = dequeue(queue);

	DEBUG == 1 ? printf("[i] Queue has been destroyed.\n") : printf("");
	return queue;
}
