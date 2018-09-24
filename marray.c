#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "marray.h"

struct morphism_array* init_morphism_array_only(int length) {
	struct morphism_array* this = malloc(sizeof(struct morphism_array));
	assert(this != NULL);
	
	// Read length
	this->length = length;

	// Malloc length
	this->array = (int *)malloc(this->length * sizeof(int));
	return this;
}

struct morphism_array* init_morphism_array(int length, int iterations) {
	struct morphism_array* this = init_morphism_array_only(length);
	
	// Generate the morphism

	return this;
}

void free_morphism_array(struct morphism_array* this) {
	assert(this != NULL);
	free(this->array);
	free(this);
}

void print_morphism_array(struct morphism_array* this) {
	int i;
	for (i = 0; i < this->length; ++i)
		putchar(this->array[i] + '0');

	putchar('\n');
}
