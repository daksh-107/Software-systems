/************************** 
Name: q16.c 
Author: Daksh Minda
Description: Program to demonstrate mandatory file locking using fcntl 
             (both write lock and read lock)
Date: 01/09/2025
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


void lock_file(int fd, short lock_type) {
    struct flock fl;
    fl.l_type = lock_type;     
    fl.l_whence = SEEK_SET;     
    fl.l_start = 0;             
    fl.l_len = 0;               

    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("fcntl lock fail");
        exit(1);
    }

    if (lock_type == F_WRLCK)
        printf("Write lock acquired.\n");
    else if (lock_type == F_RDLCK)
        printf("Read lock acquired.\n");
}

void unlock_file(int fd) {
    struct flock fl;
    fl.l_type = F_UNLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;

    if (fcntl(fd, F_SETLK, &fl) == -1) {
        perror("fcntl unlock fail");
        exit(1);
    }
    printf("Lock released.\n");
}

int main(int argc, char *argv[]) {
    int fd;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("open fail");
        exit(1);
    }

    lock_file(fd, F_WRLCK);
    write(fd, " File is locked.\n", strlen(" File is locked.\n"));
    sleep(5); 

    unlock_file(fd);

    lock_file(fd, F_RDLCK);
    sleep(5); 

    unlock_file(fd);

    close(fd);
    return 0;
}

/************************ Sample Output ******************************
$ ./q16_lock testfile.txt
Write lock acquired.
dakshLock released.
Read lock acquired.
dakshLock released.
*********************************************************************/

