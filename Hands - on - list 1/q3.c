/************************** 
Name:q3.c 
Author: Daksh Minda
Description: Program to create a new file 
             and displaying ist file descriptor value
Date: 26/08/2025
********************************************************************/


#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
 
int main(){
	int fd;
	fd = creat("newfile.txt" , 0666);

	if(fd == -1){
		perror("creat failed");
		exit(1);

	}

	printf("file created succesfully . file descriptor value = : %d\n" , fd);

	close(fd);

	return 0;
}

/************************ Sample Output ******************************
$ ./q3
file created succesfully . file descriptor value = : 3
*********************************************************************/
