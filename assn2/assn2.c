//Skyler Hill
//CS3060-X01 Fall 2022
//Assignment 2
/* Promise of Originality
I promise that this source code file has, in it's entirety, been
written by myself and by no other person or persons. If at any time an
exact copy of this source code is found to be used by another person in
this term, I understand that both myself and the student that submitted
the copy will receive a zero on this assignment.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();
    
    char *arguments[argc];
    for (int i = 1; i < argc; i++) {
        arguments[i-1] = argv[i];
    }
    arguments[argc-1] = NULL;
    
    if(pid == -1){
        //fork error
        printf("Error creating child!\n");
        return 1;
    }
    else if (pid > 0){
        //parent process
        printf("PARENT started, now waiting for process ID#%i\n", pid);
        int waitStatus;
        wait(&waitStatus);
        printf("PARENT resumed. Child exit code of %i. Now terminating parent\n", WEXITSTATUS(waitStatus));
    }
    else {
        //child process
        if (argc == 1){
            printf("CHILD started. No arguments provided. Terminating child.\n");
        }
        else if (argc == 2){
            printf("CHILD started. One argument provided. Calling execlp(), never to return (sniff)\n");
            execlp(argv[1], "", NULL);
        }
        else{
            printf("CHILD started. More than one argument provided. Calling execvp(), never to return (sniff)\n");
            execvp(arguments[0], arguments);
        }
        exit(0);
    }
}