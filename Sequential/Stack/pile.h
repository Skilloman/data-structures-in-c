#ifndef __PILE_H__
#define __PILE_H__

// Type definitions
typedef struct StackElement StackElement;
typedef int DataType;
typedef StackElement *Stack;

struct StackElement {
	DataType value;
	StackElement *next_element;
};

// Function Prototypes
Stack new_stack(void);
Stack destroy_stack(Stack st);
Stack push(Stack st, DataType value);
Stack pop(Stack st);
DataType get_top(Stack st);
void print_stack(Stack st);
int is_empty(Stack st);

#endif