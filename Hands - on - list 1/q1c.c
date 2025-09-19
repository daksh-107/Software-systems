/************************** 
Name: q1c.c
Author: Daksh Minda
Description: Program to create a fifo file
Date: 25/08/2025
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	if(mkfifo("myfifo" , 0666) == -1){
		perror("mkfifo failed");
		exit(1);
	}

	printf("fifo created : myfifo\n");
	return 0;
}

/************************ Sample Output ******************************
$ ./q1c
fifo created : myfifo
*********************************************************************/
