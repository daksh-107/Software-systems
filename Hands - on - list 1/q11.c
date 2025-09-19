/************************** 
Name:q11.c 
Author: Daksh Minda
Description: Program to create a duplicate of the
             file descriptor and then updating the file
Date: 31/08/2025
********************************************************************/


#include <stdio.h>
#include <unistd.h>   
#include <fcntl.h>    
#include <stdlib.h>   

int main() {
    int fd1, fd2;

    fd1 = open("q11test.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (fd1 == -1) {
        perror("open failed");
        exit(1);
    }

    fd2 = dup(fd1);   
    if (fd2 == -1) {
        perror("dup failed");
        close(fd1);
        exit(1);
    }
    write(fd1, "1stLine\n", 10);
    write(fd2, "2ndLine\n", 11);

    int fd3 = 7;  
    if (dup2(fd1, fd3) == -1) {
        perror("dup2 failed");
        close(fd1);
        close(fd2);
        exit(1);
    }
    write(fd3, "3rdLine\n", 10);

    int fd4 = fcntl(fd1, F_DUPFD, 0); 
    if (fd4 == -1) {
        perror("fcntl failed");
        close(fd1);
        close(fd2);
        close(fd3);
        exit(1);
    }
    write(fd4, "4thLine\n", 11);

    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);

    return 0;
}

/************************ Sample Output ******************************
$ ./q11
*********************************************************************/

