/************************** 
Name: q28.c 
Author: Daksh Minda
Description: Program to get maximum and minimum real-time priority 
             values supported by the system using scheduling policies.
Date: 04/09/2025
********************************************************************/

#include <stdio.h>
#include <sched.h>   

int main() {
    int minfifo, maxfifo;
    int minrr, maxrr;

   
    minfifo = sched_get_priority_min(SCHED_FIFO);
    maxfifo = sched_get_priority_max(SCHED_FIFO);

    
    minrr = sched_get_priority_min(SCHED_RR);
    maxrr = sched_get_priority_max(SCHED_RR);

    printf("SCHED_FIFO: Min Priority is = %d, Max Priority is = %d\n", minfifo, maxfifo);
    printf("SCHED_RR  : Min Priority is = %d, Max Priority is = %d\n", minrr, maxrr);

    return 0;
}

/************************ Sample Output ******************************
$ ./q28_rt_priority
SCHED_FIFO: Min Priority is = 1, Max Priority is = 99
SCHED_RR  : Min Priority is = 1, Max Priority is = 99
*********************************************************************/

