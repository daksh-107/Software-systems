/************************** 
Name: q26.c
Author: Daksh Minda
Description: Program to demonstrate exec system calls. 
             (a) Run an existing executable program. 
             (b) Pass arguments to another executable program.
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

        // (a) Example : Run ls -l 
        //execl("/bin/ls", "ls", "-l", NULL);

        // (b) Example: Run ./a.out with argument "Daksh"
        // Make sure a.out exists and is executable in current directory
        execl("./a.out", "a.out", "Daksh", NULL);

        perror("exec failed");
        exit(1);
    }
    else {
        
        wait(NULL);
        printf("Parent Child finished executing the new program.\n");
    }

    return 0;
}

/************************ Sample Output ******************************
Case (a) Running ls -l:
$ ./q26_exec_example
-rwxr-xr-x 1 daksh daksh 16744 Aug 28 18:20 a.out
-rw-r--r-- 1 daksh daksh  1350 Aug 28 18:19 q26_exec_example.c
...
Parent Child finished executing the new program.

Case (b) Running ./a.out with argument "Daksh":
$ ./q26_exec_example
Hello, Daksh   <-- printed by a.out
Parent Child finished executing the new program.
*********************************************************************/

