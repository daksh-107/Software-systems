/************************** 
Name: q5.c
Author: Daksh Minda
Description: program to create five new files , 
             display their fds and run a infinite loop 
	     to observe the proc directory
Date:28/08/2025 
********************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fds[5];
	char filename[20];

	for (int i = 0 ; i<5 ; i++){
		sprintf(filename , "file%d.txt" , i+1);
		fds[i] = open(filename , O_CREAT | O_RDWR , 0666);
		if(fds[i] == -1){
			perror("open failed");

			exit(1);
		}
		printf("created %s with file descriptor %d\n" , filename , fds[i]);
	}

	printf("process pid : %d\n" , getpid());
	printf("Check /proc/%d/fd/ to see the file descriptor table\n", getpid());

        while(1){
		sleep(5);
	}
	return 0;
}

/************************ Sample Output ******************************
$ ./q5 &
created file2.txt with file descriptor 3
created file2.txt with file descriptor 4
created file3.txt with file descriptor 5
created file4.txt with file descriptor 6
created file5.txt with file descriptor 7
process pid : 564
Check /proc/564/fd/ to see the file descriptor table
/proc/564/fd/
bash: /proc/564/fd/: Is a directory
daksh@LAPTOP-D1E8L557:~/ss_lab$ cd /proc/564/fd/
daksh@LAPTOP-D1E8L557:/proc/564/fd$ ls
0  1  2  3  4  5  6  7
*********************************************************************/
