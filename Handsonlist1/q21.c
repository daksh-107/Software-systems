/************************** 
Name: q21.c
Author: Daksh Minda
Description: Program to demonstrate fork(). 
             Parent process prints its PID and child’s PID, 
             while child prints its PID and parent’s PID.
Date: 03/09/2025
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t forkResult;
    pid_t ownID, parentID;

    forkResult = fork();

    if (forkResult < 0) {
        perror("fork fail");
        exit(1);
    } 
    else if (forkResult == 0) {
       
        ownID = getpid();
        parentID = getppid();
        printf("Child My Pid = %d, Parent Pid = %d\n", ownID, parentID);
    } 
    else {
        
        ownID = getpid();
        printf("Parent my Pid = %d, Child Pid = %d\n", ownID, forkResult);
    }

    return 0;
}

/************************ Sample Output ******************************
$ ./q21
Parent my Pid = 805, Child Pid = 806
Child My Pid = 806, Parent Pid = 805
*********************************************************************/

