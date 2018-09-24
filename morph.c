#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "marray.h"
#include "morph.h"

struct morphism {
	int max;
	int* length;
	int** rules;
}

struct morphism* init_morphism(int max_value) {
	struct morphism* this = malloc(sizeof(struct morphism));
	assert(this != NULL);
	this->max = max_value;

	this->length = (int*)malloc(sizeof(int) * (max_value + 1));
	this->rules = (int**)malloc(sizeof(int*) * (max_value + 1));
	assert(this->length != NULL && this->rules != NULL);
}

void free_morphism(struct morphism* this) {
	int i;
	assert(this != NULL);
	
	assert(this->length != NULL);
	free(this->length);

	assert(this->rules);
	for(i = 0; i < max; ++i) {
		if (this->rules[i] != NULL)
			free(this->rules[i]);
	}
	free(this->rules);
}

// We need to write these directly into a buffer
int apply_morphism(struct morphism* this, int n, struct morphism_array* arr, int index) {
	int i, len;
	len = this->length[n]; // Length of rule n
	for (i = 0; i < len; ++i) {
		//Read (len-1) rules
		if (index + i < arr->length) {
			arr->array[index+i] = this->rules[n][i]; //Write the corresponding rhs value to buffer.
		} else {
			return arr->length; //Cut off overflow at the end of the array.
		}
	}
	return index+i; //Return our current index
}

struct morphism_array* iterate_morphism(struct morphism *this, int times, struct morphism_array *arr) {
	struct morphism_array* temp = init_morphism_array_only(arr->length);

}
