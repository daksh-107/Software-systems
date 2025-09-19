/************************** 
Name: q4a.c 
Author: Daksh Minda
Description: Program to open a existing file using open()
Date: 26/08/2025
********************************************************************/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	int fd;
	 fd = open("newfile.txt" , O_RDWR);

	 if(fd == -1){
		 perror("open failed");
		 exit(1);


	 }
	 printf("file opened succesfully , file descriptor = : %d\n" ,fd);
	close(fd);
       return 0;
}       

/************************ Sample Output ******************************
$ ./q4a
file opened succesfully , file descriptor = : 3
*********************************************************************/
