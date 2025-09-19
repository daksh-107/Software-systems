/************************** 
Name: q1b.c
Author: Daksh Minda
Description: Program to create a hardlink to the file temporary.txt
Date:25/08/2025 
********************************************************************/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	if(link("temporary.txt" ,"hardlink.txt") == -1){
	       perror("hardlink failed");
       exit(1);
	}
 printf("hard link created : hardlink.txt(same inode as temporary.txt)\n");
return 0;
}

/************************ Sample Output ******************************
$ ./q1b
hard link created : hardlink.txt(same inode as temporary.txt)
*********************************************************************/
