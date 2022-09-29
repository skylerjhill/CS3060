CC = gcc
CFLAGS = -g -Werror - Wall -o assn1 assn1.c

assn1: Makefile
	$(CC) $(CFLAGS)

clean:
	rm -f assn1