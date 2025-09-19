/************************** 
Name: q22.c
Author: Daksh Minda
Description: Program where parent and child processes print messages 
             in sequence using fork() and wait().
Date: 03/09/2025
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t processResult;
    int childStatus;

    processResult = fork();

    if (processResult < 0) {
        perror("fork fail");
        exit(1);
    }
    else if (processResult == 0) {
      
        printf("Msg from Child: Hello I am the child process\n");
        sleep(1);
        printf("Msg Child: Done with the task.\n");
    }
    else {
        
        wait(&childStatus); 
        printf("Msg from Parent: Child has finished\n");
        printf("Msg from Parent: bye\n");
    }

    return 0;
}

/************************ Sample Output ******************************
$ ./q22
Msg from Child: Hello I am the child process
Msg Child: Done with the task.
Msg from Parent: Child has finished
Msg from Parent: bye
*********************************************************************/

