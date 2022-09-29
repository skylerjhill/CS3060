//Skyler Hill
//CS3060-X01 Fall 2022
//Assignment 1
/* Promise of Originality
I promise that this source code file has, in it's entirety, been
written by myself and by no other person or persons. If at any time an
exact copy of this source code is found to be used by another person in
this term, I understand that both myself and the student that submitted
the copy will receive a zero on this assignment.
*/

#include <stdio.h>
int main(int argc, char *argv[]){
    printf("File location: %s\n", argv[0]);
    if (argc < 2){
        printf("There were no arguments provided.\n");
        return 0;
    }
    for (int i  = 0; i  < argc; i++){
        printf("argv[%i]: %s\n", i, argv[i]);
    }
    printf("Number of arguments printed: %i\n", argc);
}