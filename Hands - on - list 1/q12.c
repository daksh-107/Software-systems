/************************** 
Name: q12.c
Author: Daksh Minda
Description: Program to identify the 
             opening mode of a file using fcntl
Date: 31/08/2025
********************************************************************/


#include <stdio.h>
#include <fcntl.h>   
#include <unistd.h>  
#include <stdlib.h>  

int main(int argc, char *argv[]) {
    int fd, flags, accmode;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDWR | O_APPEND);
    if (fd == -1) {
        perror("open failed");
        exit(1);
    }

    flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl failed");
        close(fd);
        exit(1);
    }

    accmode = flags & O_ACCMODE;

    if (accmode == O_RDONLY)
        printf("opened in READ only mode\n");
    else if (accmode == O_WRONLY)
        printf("opened in WRITE only mode\n");
    else if (accmode == O_RDWR)
        printf("opened in READ-WRITE mode\n");

    if (flags & O_APPEND)
        printf("APPEND flag set\n");

    if (flags & O_NONBLOCK)
        printf("NONBLOCK flag set\n");

    close(fd);
    return 0;
}


/***************SAMPLE OUTPUT:*********************
  
opened in READ-WRITE mode
APPEND flag set

***************************************************/
