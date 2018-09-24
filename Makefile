CC = gcc
RACO = raco

all: asquare

asquare:
	$(CC) asquare.c marray.c -o asquare

.PHONY: clean
clean:
	rm -f asquare
