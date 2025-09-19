/************************** 
Name: q27.c 
Author: Daksh Minda
Description: Program to demonstrate different exec() system calls 
             to execute the command "ls -Rl".
Date: 04/09/2025
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;  

int main() {
    pid_t childPid;

    // (a) 
    childPid = fork();
    if (childPid == 0) {
        printf("\n-- Using execl --\n");
        execl("/bin/ls", "ls", "-Rl", NULL);
        perror("execl fail");
        exit(1);
    }
    wait(NULL);

    // (b)
    childPid = fork();
    if (childPid == 0) {
        printf("\n-- Using execlp --\n");
        execlp("ls", "ls", "-Rl", NULL);
        perror("execlp fail");
        exit(1);
    }
    wait(NULL);

    // (c)
    childPid = fork();
    if (childPid == 0) {
        printf("\n-- Using execle --\n");
        execle("/bin/ls", "ls", "-Rl", NULL, environ);
        perror("execle fail");
        exit(1);
    }
    wait(NULL);

    // (d)
    childPid = fork();
    if (childPid == 0) {
        printf("\n-- Using execv --\n");
        char *args[] = {"ls", "-Rl", NULL};
        execv("/bin/ls", args);
        perror("execv fail");
        exit(1);
    }
    wait(NULL);

    // (e) 
    childPid = fork();
    if (childPid == 0) {
        printf("\n-- Using execvp --\n");
        char *args[] = {"ls", "-Rl", NULL};
        execvp("ls", args);
        perror("execvp fail");
        exit(1);
    }
    wait(NULL);

    printf("\nAll demonstrations completed.\n");
    return 0;
}

/************************ Sample Output ******************************
$ ./q27

--- Using execl ---
.:
total 56
-rwxr-xr-x 1 daksh daksh 16392 Aug 28 18:35 q27_exec_variants
-rw-r--r-- 1 daksh daksh  1456 Aug 28 18:33 q27_exec_variants.c

--- Using execlp ---
(same ls -Rl output)

--- Using execle ---
(same ls -Rl output)

--- Using execv ---
(same ls -Rl output)

--- Using execvp ---
(same ls -Rl output)

All demonstrations completed.
*********************************************************************/

