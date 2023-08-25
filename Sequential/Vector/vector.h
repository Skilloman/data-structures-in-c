#ifndef __VECTOR_H__
#define __VECTOR_H__

// Type definitions
typedef int DataType;
typedef struct
{
	int size;
	int capacity;
	int *data;
} Vect;

// Function prototypes
Vect *init_vector(int capacity);
Vect *destroy_vector(Vect *vector);
DataType get_vector(Vect *vector, int index);
int is_vector_destroyed(Vect *vector);
void resize_vector(Vect *vector, int size);
void replace_data(Vect *vector, DataType *data, int size);
void set_vector(Vect *vector, int index, DataType value);
void print_vect(Vect *vector);

#endif