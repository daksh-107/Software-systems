/************************** 
Name: q17.c 
Author: Daksh Minda
Description: Program to simulate online ticket reservation. 
             One program initializes the ticket number, 
             another program applies a write lock, reads it, increments, 
             then updates it safely.
Date: 01/09/2025
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void apply_write_lock(int fileDesc) {
    struct flock fileLock;
    fileLock.l_type = F_WRLCK;     
    fileLock.l_whence = SEEK_SET;  
    fileLock.l_start = 0;
    fileLock.l_len = 0;            

    if (fcntl(fileDesc, F_SETLKW, &fileLock) == -1) {
        perror("write lock fail");
        exit(1);
    }
}


void release_lock(int fileDesc) {
    struct flock fileLock;
    fileLock.l_type = F_UNLCK;
    fileLock.l_whence = SEEK_SET;
    fileLock.l_start = 0;
    fileLock.l_len = 0;

    if (fcntl(fileDesc, F_SETLK, &fileLock) == -1) {
        perror("unlock fail");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    int fileHandle;
    int ticketValue;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ticket_file>\n", argv[0]);
        exit(1);
    }

    fileHandle = open(argv[1], O_RDWR | O_CREAT, 0666);
    if (fileHandle == -1) {
        perror("open fail");
        exit(1);
    }

    
    apply_write_lock(fileHandle);

    
    lseek(fileHandle, 0, SEEK_SET);
    if (read(fileHandle, &ticketValue, sizeof(ticketValue)) <= 0) {
        ticketValue = 0;  
    }

    ticketValue++; 

    lseek(fileHandle, 0, SEEK_SET);
    if (write(fileHandle, &ticketValue, sizeof(ticketValue)) == -1) {
        perror("write fail");
        release_lock(fileHandle);
        close(fileHandle);
        exit(1);
    }

    printf("New ticket number issued: %d\n", ticketValue);

    release_lock(fileHandle);

    close(fileHandle);
    return 0;
}

/************************ Sample Output ******************************
$ ./q17_ticket ticket.txt
New ticket number issued: 1

# Running again simulates another user reserving:
$ ./q17_ticket ticket.txt
New ticket number issued: 2

$ ./q17_ticket ticket.txt
New ticket number issued: 3
*********************************************************************/

