/************************** 
Name: q19.c 
Author: Daksh Minda
Description: Program to measure the execution time of getpid() system call 
             using CPU time stamp counter (RDTSC).
Date: 02/09/2025
********************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>


static __inline__ unsigned long long readTSC(void) {
    unsigned hi, lo;
    __asm__ volatile ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long)lo) | (((unsigned long long)hi) << 32);
}

int main() {
    unsigned long long startCycles, endCycles;
    pid_t processID;

    startCycles = readTSC();        
    processID = getpid();           
    endCycles = readTSC();         

    printf("Process id: %d\n", processID);
    printf("cycles taken by getpid: %llu\n", (endCycles - startCycles));

    return 0;
}

/************************ Sample Output ******************************
$ ./q19
Process id: 749
cycles taken by getpid: 10240
*********************************************************************/

