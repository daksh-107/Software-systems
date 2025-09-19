/************************** 
Name: q24.c
Author: Daksh Minda
Description: Program to demonstrate an orphan process. 
             Parent exits quickly, child keeps running, 
             then gets adopted by init/systemd.
Date: 03/09/2025
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t forkRes;

    forkRes = fork();

    if (forkRes < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (forkRes == 0) {
        
        printf("[Child] My PID = %d, my Parent PID = %d\n", getpid(), getppid());
        sleep(5); 
        printf("[Child] After 5 seconds my new Parent Pid = %d\n", getppid());
        printf("[Child] I have become orphan and was adopted by init/systemd.\n");
    }
    else {
       
        printf("Parent My PID = %d, exiting now. Child Pid = %d\n", getpid(), forkRes);
        exit(0);
    }

    return 0;
}

/************************ Sample Output ******************************
$ ./q24
Parent My PID = 850, exiting now. Child Pid = 851
[Child] My PID = 851, my Parent PID = 850
[Child] After 5 seconds my new Parent Pid = 300
[Child] I have become orphan and was adopted by init/systemd.
*********************************************************************/

