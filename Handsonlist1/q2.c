/************************** 
Name: q2.c
Author: Daksh Minda
Description: Program to run an infinite loop 
             and observe the proc directory using the pid
Date: 25/08/2025
********************************************************************/
#include<stdio.h>
#include<unistd.h>

int main(){
	while(1){
		printf("running process pid : %d \n" , getpid());
		sleep(5);
	}
	return 0;
}

/************************ Sample Output ******************************
$ ./q2 &
running process pid : 543
running process pid : 543
running process pid : 543
running process pid : 543
running process pid : 543
running process pid : 543
running process pid : 543
killrunning process pid : 543
 543
*********************************************************************/

