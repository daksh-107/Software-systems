/*
============================================================================
Name : q22.c
Author : Daksh Minda
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file
Date: 03/09/2025
============================================================================
*/

#include <unistd.h>    	
#include <sys/types.h> 	
#include <sys/stat.h>  	
#include <fcntl.h>     	
#include <stdio.h> 	
int main(int argc, char *argv[]){
	if(argc < 2){
		perror("Enter File Name\n");
		return 0;
	}
	int fd;
	if((fd = open(argv[1],O_RDWR | O_CREAT | O_APPEND)) == -1){
		perror("FD\n");
		return 0;
	}
	if(fork()){
		write(fd,"PARENT\n",7);
	}else{
		write(fd,"CHILD\n",6);
	}
	close(fd);
	return 0;
}
/*
cat b.txt 
PARENT
CHILD
*/

