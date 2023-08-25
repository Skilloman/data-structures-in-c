#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

Vect *init_vector(int capacity)
{
	Vect *vector = (Vect*)calloc(1, sizeof(Vect));
	if(vector == NULL)
	{
		fprintf(stderr, "[!] Dynamic allocation error.\n");
		exit(EXIT_FAILURE);
	}

	vector->capacity = capacity;
	vector->size = 0;
	vector->data = (DataType*)calloc(capacity, sizeof(DataType));

	if(vector->data == NULL)
	{
		fprintf(stderr, "[!] Dynamic allocation error.\n");
		exit(EXIT_FAILURE);
	}

	return vector;
}

void resize_vector(Vect *vector, int size)
{
	if(is_vector_destroyed(vector))
	{
		fprintf(stderr, "[!] Impossible, vector has been destroyed.\n");
		exit(EXIT_FAILURE);
	}

	if(size < vector->size)
	{
		fprintf(stderr, "[!] Unable to resize, this would result in data loss.\n");
		return;
	}

	if(size == vector->size)
	{
		fprintf(stderr, "[!] No need to resize, the vector is already of size %d.\n", vector->capacity);
		return;
	}
	
	if(size <= vector->capacity)
	{
		vector->size = size;
		return;
	}

	DataType *backup_data = vector->data;
	vector->data = (DataType*)calloc(size, sizeof(DataType));
	vector->capacity = size;

	for(int i = 0; i < vector->size; i++)
		vector->data[i] = backup_data[i];

	vector->size = size;
	free(backup_data);
	return;
}

void replace_data(Vect *vector, DataType *data, int size)
{
	if(is_vector_destroyed(vector))
	{
		fprintf(stderr, "[!] Impossible, vector has been destroyed.\n");
		exit(EXIT_FAILURE);
	}

	if(size != vector->size)
	{
		fprintf(stderr, "[!] The array must be of the size of the vector.\n");
		exit(EXIT_FAILURE);
	}

	for(int i = 0; i < size; i++)
	{
		vector->data[i] = data[i];
	}

	return;
}

DataType get_vector(Vect *vector, int index)
{
	if(is_vector_destroyed(vector))
	{
		fprintf(stderr, "[!] Impossible, vector has been destroyed.\n");
		exit(EXIT_FAILURE);
	}

	if(index > vector->size || index < 0)
	{
		fprintf(stderr, "[!] Invalid index.\n");
		exit(EXIT_FAILURE);
	}

	return vector->data[index];
}

Vect* destroy_vector(Vect *vector)
{
	if(is_vector_destroyed(vector))
	{
		fprintf(stderr, "[!] Impossible, vector has arleady been destroyed.\n");
		exit(EXIT_FAILURE);
	}

	free(vector->data);
	vector->data = NULL;

	vector->size = 0;
	vector->capacity = 0;

	free(vector);
	return NULL;
}

void set_vector(Vect *vector, int index, DataType value)
{
	if(is_vector_destroyed(vector))
	{
		fprintf(stderr, "[!] Impossible, vector has been destroyed.\n");
		exit(EXIT_FAILURE);
	}

	if(index >= vector->size || index < 0)
	{
		fprintf(stderr, "[!] Invalid index.\n");
		exit(EXIT_FAILURE);
	}

	vector->data[index] = value;
}

void print_vect(Vect *vector)
{
	if(is_vector_destroyed(vector))
	{
		fprintf(stderr, "[!] Impossible, vector has been destroyed.\n");
		exit(EXIT_FAILURE);
	}

	printf("*** Display of the Vector ***\n");
	printf("Size : %d\n", vector->size);
	printf("Capacity : %d\n", vector->capacity);
	printf("Data : ");

	for(int i = 0; i < vector->size; i++)
		printf("%d ", vector->data[i]);

	printf("\n\n");
	return;
}

int is_vector_destroyed(Vect *vector)
{
	return vector == NULL ? 1 : 0;
}
