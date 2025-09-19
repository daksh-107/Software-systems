/************************** 
Name: q1a.c
Author: Daksh Minda
Description: Program to create a softlink to the file temporary.txt
Date:25/08/2025 
********************************************************************/


# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>

int main(){
	if(symlink("temporary.txt" , "softlink.txt") == -1 ){
		perror("symlink failed");
		exit(1);



	}

	printf("softlink softlink.txt -> temporary.txt created \n");
	return 0;
}

/************************ Sample Output ******************************
$ ./q1a
softlink softlink.txt -> temporary.txt created
*********************************************************************/

