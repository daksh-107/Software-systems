/************************** 
Name: q25.c
Author: Daksh Minda
Description: Program to create 3 child processes. 
             Parent waits for one specific child using waitpid().
Date: 03/09/2025
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t childPids[3];
    int i, exitStatus;

   
    for (i = 0; i < 3; i++) {
        childPids[i] = fork();

        if (childPids[i] < 0) {
            perror("fork fail");
            exit(1);
        }
        else if (childPids[i] == 0) {
         
            printf("[Child %d] PID = %d, Parent Pid = %d\n", i+1, getpid(), getppid());
            sleep(2 + i); 
            printf("[Child %d] PID = %d finishd work.\n", i+1, getpid());
            exit(100 + i);
        }
    }

    
    pid_t waitedPID = childPids[1];
    pid_t finishedChild = waitpid(waitedPID, &exitStatus, 0);

    if (finishedChild == -1) {
        perror("waitpid failed");
        exit(1);
    }

    if (WIFEXITED(exitStatus)) {
        printf("[Parent] Waited for Child with PID %d, exited with code %d\n",
               finishedChild, WEXITSTATUS(exitStatus));
    }

   
    while (wait(NULL) > 0);

    return 0;
}

/************************ Sample Output ******************************
$ ./q25
[Child 1] PID = 871, Parent Pid = 870
[Child 2] PID = 872, Parent Pid = 870
[Child 3] PID = 873, Parent Pid = 870
[Child 1] PID = 871 finishd work.
[Child 2] PID = 872 finishd work.
[Parent] Waited for Child with PID 872, exited with code 101
[Child 3] PID = 873 finishd work.
*********************************************************************/

