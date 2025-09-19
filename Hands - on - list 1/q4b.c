/************************** 
Name: q4b.c
Author: Daksh Minda
Description: Program to create and open 
             a new file using open() with excl flag 
Date:27/08/2025 
********************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd;
	fd = open("newfile2.txt" , O_CREAT | O_EXCL | O_RDWR , 0666);

	if(fd == -1){
		perror("open exclusisvely failed");
		exit(1);

	}

	printf("file created exclusively , file descriptor = : %d\n" , fd);
       close(fd);
       return 0;
}

/************************ Sample Output ******************************
$ ./q4b
file created exclusively , file descriptor = : 3
*********************************************************************/
