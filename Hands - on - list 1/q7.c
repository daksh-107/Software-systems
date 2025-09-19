/************************** 
Name: q7.c
Author: Daksh Minda
Description: Program to copy the data from 
             a pre existing file to a new file
Date:29/08/2025 
********************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

#define BUF_SIZE 1024

int main(int argc , char *argv[]){
	int fd1 , fd2;
	char buffer[BUF_SIZE];
	int n;

	if(argc!=3){
		write(2 , "usage : ./q7copydata file1.txt file2.txt\n" , 30);
	       exit(1);
        }
        
        fd1 = open(argv[1] , O_RDONLY);
        if(fd1 == -1){
	  perror("open source file failed");
          exit(1);
	}

	fd2 = open(argv[2] , O_WRONLY | O_CREAT | O_TRUNC , 06660);
	if(fd2 == -1){
		perror("open destination file failed");
		close(fd1);
		exit(1);
	}

	while( n = (read(fd1 , buffer , BUF_SIZE))){
			if(write(fd2 , buffer ,n) != n){
			   perror("write failed");
			   close(fd1);
			   close(fd2);
			   exit(1);
			}
			
	}

        if(n<0){
          perror("read failed");
	}
        close(fd1);
        close(fd2);
        return 0;
	
}	

/************************ Sample Output ******************************
$ ./q7 q7test1.txt q7test2.txt

*********************************************************************/
			    
			
			
			


	

        	

