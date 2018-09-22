CC = gcc
RACO = raco

all: asquare

asquare:
	$(CC) asquare.c -o asquare

.PHONY: clean
clean:
	rm -f asquare
