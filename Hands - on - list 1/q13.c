/*******************************************************************
Name: q13.c
Author: Daksh Minda
Description: Program to wait for STDIN for 10 seconds using select()
Date: 31/08/2025
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

int main() {
    fd_set readfds;
    struct timeval tv;
    int retval;
    char buffer[100];

    
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    printf("Waiting for input.. (10 secs timer)\n");
    retval = select(1, &readfds, NULL, NULL, &tv);

    if (retval == -1) {
        perror("select failed");
        exit(1);
    } else if (retval == 0) {
        printf("Timeout: No input provided \n");
    } else {
        
        int n = read(0, buffer, sizeof(buffer) - 1);
        if (n > 0) {
            buffer[n] = '\0'; 
            printf("You typed: %s", buffer);
        }
    }

    return 0;
}

/************************ Sample Output ****************************
$ ./q13
Waiting for input.. (10 secs timer)
hey daksh this side
You typed: hey daksh this side
*********************************************************************/

