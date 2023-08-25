#ifndef __PILE_H__
#define __PILE_H__


// Type definitions
typedef int DataType;
typedef struct Cell Cell;
typedef Cell* Queue;

// Struct definitions
struct Cell {
	DataType value;
	Cell *next_cell;
};

// Function prototypes
Queue new_queue(void);
Queue dequeue(Queue queue);
Queue clear_queue(Queue queue);
Queue enqueue(Queue queue, DataType value);

DataType get_back(Queue queue);
DataType get_front(Queue queue);

int length(Queue queue);
int is_empty(Queue queue);

void print_queue(Queue queue);

#endif