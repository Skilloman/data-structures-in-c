#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main(void)
{
	// Sample data
	DataType array_data[5] = {1, 2, 3, 4, 5};
	int size = sizeof(array_data) / sizeof(DataType);

	// Initialisation of a vector (capacity=5)
	Vect *vec = init_vector(5);

	// Resize to size=5 in order to put 'array_data'
	resize_vector(vec, 5);

	// Replace the empty array with 'array_data'
	replace_data(vec, array_data, size);
	print_vect(vec); // and print the current state

	// Set the third value to 6
	printf("( I'm replacing the third value by 6 ... )\n");
	set_vector(vec, 3-1, 6);
	printf("The third value is : %d\n", get_vector(vec, 3-1));

	// Destroy the vector
	vec = destroy_vector(vec);

	return 0;
}