/************************** 
Name: q23.c
Author: Daksh Minda
Description: Program to demonstrate a zombie process. 
             Child exits immediately, parent sleeps without wait(), 
             leaving the child as a zombie.
Date: 03/09/2025
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t forkoc;

    forkoc = fork();

    if (forkoc < 0) {
        perror("fork fail");
        exit(1);
    }
    else if (forkoc == 0) {
        
        printf("Child Pid = %d, exiting now.\n", getpid());
        exit(0);
    }
    else {
      
        printf("Parent Pid = %d, child Pid = %d created.\n", getpid(), forkoc);
        printf("Parent Sleeping 20 seconds. Check child status with 'ps -l'.\n");
        sleep(20);
        printf("Parent Wokeup, exiting now.\n");
    }

    return 0;
}

/************************ Sample Output ******************************
$ ./q23
Parent Pid = 834, child Pid = 835 created.
Parent Sleeping 20 seconds. Check child status with 'ps -l'.
Child Pid = 835, exiting now.
*********************************************************************/

