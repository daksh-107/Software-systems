/************************** 
Name:q10.c 
Author: Daksh Minda
Description: Program to move 
             the file offset using lseek
Date: 30/08/2025
********************************************************************/


#include <stdio.h>
#include <unistd.h>  
#include <fcntl.h>    
#include <stdlib.h>   

int main() {
    int fd;
    off_t offset;

    fd = open("q10test.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open failed");
        exit(1);
    }

    if (write(fd, "AAAAAAAAAA", 10) != 10) {
        perror("write failed");
        close(fd);
        exit(1);
    }

    offset = lseek(fd, 10, SEEK_CUR);
    if (offset == (off_t)-1) {
        perror("lseek failed");
        close(fd);
        exit(1);
    }
    printf("Current file offset after lseek = %ld\n", (long)offset);

    if (write(fd, "BBBBBBBBBB", 10) != 10) {
        perror("write faild");
        close(fd);
        exit(1);
    }

    close(fd);
    return 0;
}

/************************ Sample Output ******************************
$ ./q10
Current file offset after lseek = 20
*********************************************************************/
