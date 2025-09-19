/************************** 
Name: q8.c
Author: Daksh Minda
Description: Program to read a file line by line 
Date:29/08/2025 
********************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define BUF_SIZE 1

int main(int argc , char *argv[]){
	int fd ;
	char c;
	int n;

	if(argc !=2){
		write(2 , "Usage: ./q8_read_lines filename\n" , 32);
		exit(1);
	}

	fd = open(argv[1] , O_RDONLY);
	if(fd == -1){
		perror("open faild");
		exit(1);
	}

	while( n = read(fd , &c , BUF_SIZE) > 0){

		write(1 , &c ,1);
	}
	if(n<0){
		perror("read failed");
	}
	close(fd);
	return 0;
}

/************************ Sample Output ******************************
$ ./q8 q8test.txt
line 1
line 2
line 3
line 4
*********************************************************************/
