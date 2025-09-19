/************************** 
Name: q29.c
Author: Daksh Minda
Description: Program to get and modify the scheduling policy of the process. 
             Demonstrates SCHED_FIFO and SCHED_RR usage.
Date: 04/09/2025
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int current;
    struct sched_param scheduleConfig;

  
    current = sched_getscheduler(0);  
    if (current == -1) {
        perror("sched_getscheduler failed");
        exit(1);
    }

    printf("Current Scheduling Policy: ");
    switch (current) {
        case SCHED_OTHER: printf("SCHED_OTHER (normal)\n"); break;
        case SCHED_FIFO:  printf("SCHED_FIFO (Real-time fifo)\n"); break;
        case SCHED_RR:    printf("SCHED_RR (Real-time Round Robin)\n"); break;
        default:          printf("Unknown Policy\n");
    }

 
    if (argc == 2) {
        if (strcmp(argv[1], "fifo") == 0) {
            scheduleConfig.sched_priority = sched_get_priority_max(SCHED_FIFO);
            if (sched_setscheduler(0, SCHED_FIFO, &scheduleConfig) == -1) {
                perror("sched_setscheduler (fifo) fail");
                exit(1);
            }
            printf("Scheduling policy changed to SCHED_FIFO with priority %d\n",
                   scheduleConfig.sched_priority);
        }
        else if (strcmp(argv[1], "rr") == 0) {
            scheduleConfig.sched_priority = sched_get_priority_max(SCHED_RR);
            if (sched_setscheduler(0, SCHED_RR, &scheduleConfig) == -1) {
                perror("sched_setscheduler (rr) fail");
                exit(1);
            }
            printf("Scheduling policy changed to SCHED_RR with priority %d\n",
                   scheduleConfig.sched_priority);
        }
        else {
            printf("Invalid option. Use 'fifo' or 'rr'.\n");
        }
    }

    return 0;
}

/************************ Sample Output ******************************
# Run without arguments
$ ./q29
Current Scheduling Policy: SCHED_OTHER (normal)

# Run with "fifo" (requires sudo)
$ sudo ./q29 fifo
[sudo] password for daksh:
Current Scheduling Policy: SCHED_OTHER (normal)
Scheduling policy changed to SCHED_FIFO with priority 99

# Run with "rr" (requires sudo)
$ sudo ./q29 rr
[sudo] password for daksh:
Current Scheduling Policy: SCHED_OTHER (normal)
Scheduling policy changed to SCHED_RR with priority 99
*********************************************************************/

