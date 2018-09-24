#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct morphism;

struct morphism* init_morphism(/* morphism rules go here */);
void free_morphism(struct morphism* this);
int apply_morphism(int n);
