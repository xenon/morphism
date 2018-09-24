#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct morphism_array {
	int length;
	int* array;
};

struct morphism_array* init_morphism_array_only(int length);
struct morphism_array* init_morphism_array(int length, int iterations);
void free_morphism_array(struct morphism_array* this);
void print_morphism_array(struct morphism_array* this);
