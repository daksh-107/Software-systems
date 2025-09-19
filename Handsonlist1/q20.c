/************************** 
Name:q20.c 
Author: Daksh Minda
Description: Program to measure the execution time of getppid() system call 
             using CPU time stamp counter (RDTSC).
Date: 02/09/2025
********************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

static __inline__ unsigned long long readClockCounter(void) {
    unsigned highBits, lowBits;
    __asm__ volatile ("rdtsc" : "=a"(lowBits), "=d"(highBits));
    return ((unsigned long long)lowBits) | (((unsigned long long)highBits) << 32);
}

int main() {
    unsigned long long cycleS, cycleE;
    pid_t parentID;

    cycleS = readClockCounter();

    parentID = getppid();  

    
    cycleE = readClockCounter();

    printf("Parent process id: %d\n", parentID);
    printf("Cycles taken by getppid: %llu\n", (cycleE - cycleS));

    return 0;
}

/************************ Sample Output ******************************
$ ./q20
Parent process id: 396
Cycles taken by getppid: 10336
*********************************************************************/

