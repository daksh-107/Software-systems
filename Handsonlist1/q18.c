/************************** 
Name: q18.c
Author: Daksh Minda
Description: Program to demonstrate record-level locking 
             (both write lock and read lock) using fcntl.
Date: 02/09/2025
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


void putLock(int fileDescriptor, short lockKind, off_t offsetPos, off_t lengthRec) {
    struct flock recordLock;
    recordLock.l_type = lockKind;     
    recordLock.l_whence = SEEK_SET;
    recordLock.l_start = offsetPos;   
    recordLock.l_len = lengthRec;   

    if (fcntl(fileDescriptor, F_SETLKW, &recordLock) == -1) {
        perror("locking fail");
        exit(1);
    }

    if (lockKind == F_WRLCK)
        printf("Write lock applied on record on offset %ld\n", (long)offsetPos);
    else if (lockKind == F_RDLCK)
        printf("Read lock applied on record on offset %ld\n", (long)offsetPos);
}


void removeLock(int fileDescriptor, off_t offsetPos, off_t lengthRec) {
    struct flock recordLock;
    recordLock.l_type = F_UNLCK;
    recordLock.l_whence = SEEK_SET;
    recordLock.l_start = offsetPos;
    recordLock.l_len = lengthRec;

    if (fcntl(fileDescriptor, F_SETLK, &recordLock) == -1) {
        perror("unlock fail");
        exit(1);
    }

    printf("Lock released for record on offset %ld\n", (long)offsetPos);
}

int main(int argc, char *argv[]) {
    int handleFile;
    char recordBuffer[50];
    off_t recordSize = sizeof(recordBuffer);

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <records_file>\n", argv[0]);
        exit(1);
    }

    
    handleFile = open(argv[1], O_RDWR | O_CREAT, 0666);
    if (handleFile == -1) {
        perror("open fail");
        exit(1);
    }

    
    off_t offsetTarget = 1 * recordSize;

   
    putLock(handleFile, F_WRLCK, offsetTarget, recordSize);

    
    lseek(handleFile, offsetTarget, SEEK_SET);
    strcpy(recordBuffer, "This is the updated record 2.\n");
    write(handleFile, recordBuffer, strlen(recordBuffer));

    sleep(5); 

    
    removeLock(handleFile, offsetTarget, recordSize);

   
    putLock(handleFile, F_RDLCK, offsetTarget, recordSize);
    lseek(handleFile, offsetTarget, SEEK_SET);
    read(handleFile, recordBuffer, sizeof(recordBuffer));
    printf("Read from Record: %s\n", recordBuffer);
    removeLock(handleFile, offsetTarget, recordSize);

    close(handleFile);
    return 0;
}

/************************ Sample Output ******************************
$ ./q18 q18test.txt
Write lock applied on record on offset 50
Lock released for record on offset 50
Read lock applied on record on offset 50
Read from Record: This is the updated record 2.
*********************************************************************/

