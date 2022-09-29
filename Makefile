CC = gcc
CFLAGS = -g -Werror -Wall

assn1: Makefile
	$(CC) $(CFLAGS) assn1.c -o assn1

clean:
	rm -f assn1