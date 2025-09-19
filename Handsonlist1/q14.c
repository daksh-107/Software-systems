/*******************************************************************
Name: q14.c
Author: Daksh Minda
Description: Program to find the type of a file using stat()
Date: 01/09/2025
********************************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s q14\n", argv[0]);
        exit(1);
    }

    if (stat(argv[1], &fileStat) == -1) {
        perror("stat failed");
        exit(1);
    }

    if (S_ISREG(fileStat.st_mode))
        printf("%s is  Regular file\n", argv[1]);
    else if (S_ISDIR(fileStat.st_mode))
        printf("%s is  Directory\n", argv[1]);
    else if (S_ISLNK(fileStat.st_mode))
        printf("%s is  Symbolic link\n", argv[1]);
    else if (S_ISCHR(fileStat.st_mode))
        printf("%s is  Character device\n", argv[1]);
    else if (S_ISBLK(fileStat.st_mode))
        printf("%s is  Block device\n", argv[1]);
    else if (S_ISFIFO(fileStat.st_mode))
        printf("%s is  FIFO (named pipe)\n", argv[1]);
    else if (S_ISSOCK(fileStat.st_mode))
        printf("%s is  Socket\n", argv[1]);
    else
        printf("%s Unknown type\n", argv[1]);

    return 0;
}

/************************ Sample Output ******************************
$ ./q14 q14test.txt
q14test.txt is Regular file

$ ./q14 myfifo
myfifo is FIFO (named pipe)
*********************************************************************/

