/*
============================================================================
Name : q20.c
Author : Daksh Minda
Description :  Find out the priority of your running program. Modify the priority with nice command.
Date: 01/09/2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <errno.h>

int main()
{
    int initial_priority;
    initial_priority = getpriority(PRIO_PROCESS, 0);
    printf("Current process priority (niceness) is: %d\n", initial_priority);

    int niceness_to_add = 10;
    
    errno = 0;
    nice(niceness_to_add);a

    if (errno != 0) {
        perror("Error setting new priority");
        return 1;
    }

    int updated_priority;
    updated_priority = getpriority(PRIO_PROCESS, 0);
    printf("New process priority (niceness) is: %d\n", updated_priority);
    return 0;
}
/*
Output:
Current process priority (niceness) is:0
New process priority (niceness) is: 10
*/

