/************************** 
Name:q6.c 
Author: Daksh Minda
Description: Program to read an input 
             from SDIN and output in SDOUT
Date: 28/08/2025
********************************************************************/


#include <unistd.h>   
#include <stdlib.h>   
#include <stdio.h>    

int main() {
    char buffer[100];
    int n;

    while ((n = read(0, buffer, sizeof(buffer))) > 0) {
        if (write(1, buffer, n) < 0) {
            perror("write failed");
            exit(1);
        }
    }

    if (n < 0) { 
        perror("read failed");
        exit(1);
    }

    return 0;
}

/************************ Sample Output ******************************
$ ./q6
daksh
daksh
hello
hello
*********************************************************************/

