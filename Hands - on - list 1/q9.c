/************************** 
Name: q9.c
Author: Daksh Minda
Description: Program to display 
             the stat info regarding a file
Date:30/08/2025 
********************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>

int main(int argc , char *argv[]){
	struct stat filestats;

	if(argc != 2){

		fprintf(stderr , "usage: %s temporary.txt \n" , argv[0]);
	       exit(1);
	}

	if(stat(argv[1] , &filestats) == -1){
		perror("statfailed");
		exit(1);
	}

	printf("File: %s\n", argv[1]);
        printf("Inode: %ld\n", (long) filestats.st_ino);
        printf("Number of hard links: %ld\n", (long) filestats.st_nlink);
        printf("UID: %d\n", filestats.st_uid);
        printf("GID: %d\n", filestats.st_gid);
        printf("Size: %ld bytes\n", (long) filestats.st_size);
        printf("Block size: %ld\n", (long) filestats.st_blksize);
        printf("Number of blocks: %ld\n", (long) filestats.st_blocks);

	printf("last acces :  %s" ,   ctime(&filestats.st_atime));
	printf("last modification :  %s" , ctime(&filestats.st_mtime));
	printf("last status change : %s" , ctime(&filestats.st_ctime));

	return 0;
}

/************************ Sample Output ******************************
$ ./q9 temporary.txt
File: temporary.txt
Inode: 43831
Number of hard links: 2
UID: 1001
GID: 1001
Size: 101 bytes
Block size: 4096
Number of blocks: 8
last acces :  Sat Sep  6 12:15:19 2025
last modification :  Sat Sep  6 12:15:34 2025
last status change : Sun Sep  7 11:23:50 2025
*********************************************************************/


