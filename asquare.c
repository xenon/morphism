#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "marray.h"

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
	int length, i;
	char c;
	struct morphism_array* morphism;
	
	scanf("%d", &length);

	morphism = init_morphism_array_only(length);

	for (i = 0; i < morphism->length; ++i) {
		// Store the number (we are aligning ASCII back to integers)
		c = getchar();
		assert(c != EOF);
		morphism->array[i] = c - '0';
	}
	
	//print_morphism_array(read_morphism);
	if (check_for_square(morphism)) {
		printf("Morphism contains an additive square\n");
	} else {
		printf("Morphism does not contain an additive square\n");
	}
	free_morphism_array(morphism);
	return 0;
}
