#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct morphism_array {
	int length;
	int* array;
};

struct morphism_array* init_morphism_array(void) {
	int i;
	char c;
	struct morphism_array* morphism = malloc(sizeof(struct morphism_array));
	assert(morphism != NULL);
	
	// Read length
	scanf("%d", &(morphism->length));

	// Malloc length
	morphism->array = (int *)malloc(morphism->length * sizeof(int));
	for (i = 0; i < morphism->length; ++i) {
		// Store the number (we are aligning ASCII back to integers)
		c = getchar();
		assert(c != EOF);
		morphism->array[i] = c - '0';
	}

	return morphism;
}

void free_morphism_array(struct morphism_array* morphism) {
	assert(morphism != NULL);
	free(morphism->array);
	free(morphism);
}

void print_morphism_array(struct morphism_array* morphism) {
	int i;
	for (i = 0; i < morphism->length; ++i)
		putchar(morphism->array[i] + '0');

	putchar('\n');
}

int checksum(struct morphism_array* morphism, int start, int end) {
	int i, sum;
	sum = 0;
	for (i = start; i < end; ++i) {
		sum += morphism->array[i];
	}
	return sum;
}

bool check_for_square(struct morphism_array* morphism) {
	int l, i, max_i, max_l;
	int a, b;
	max_l = morphism->length / 2 + 1;
	
	for (l = 1; l < max_l; ++l) {
		max_i = morphism->length - (2 * l);
		for (i = 0; i < max_i; ++i) {
			a = checksum(morphism, i, i+l);
			b = checksum(morphism, i+l, i+(2*l));
			if (a == b) return true;
		}
	}

	return false;
}

int
main
(int argc, char** argv)
{
	struct morphism_array* read_morphism = init_morphism_array();
	//print_morphism_array(read_morphism);
	if (check_for_square(read_morphism)) {
		printf("Morphism contains an additive square\n");
	} else {
		printf("Morphism does not contain an additive square\n");
	}
	free_morphism_array(read_morphism);
	return 0;
}
