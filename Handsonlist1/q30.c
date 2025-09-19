/************************** 
Name: q30.h 
Author: Daksh Minda
Description: Program to create a daemon process that runs script 
             at a specific time (HH:MM).
Date: 04/09/2025
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]) {
    pid_t daemonPid;
    int targeth, targetm;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hr 0-23> <min 0-59> <script-path>\n", argv[0]);
        exit(1);
    }

    targeth = atoi(argv[1]);
    targetm = atoi(argv[2]);
    char *scriptPath = argv[3];

    daemonPid = fork();
    if (daemonPid < 0) {
        perror("fork fail");
        exit(1);
    }
    if (daemonPid > 0) {
 
        exit(0);
    }

    if (setsid() < 0) exit(1);

    chdir("/");
   
    umask(0);

    
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1) {
        time_t currentTime;
        struct tm *timeinf;

        time(&currentTime);
        timeinf = localtime(&currentTime);

        if (timeinf->tm_hour == targeth && timeinf->tm_min == targetm) {
           
            system(scriptPath);
           
            sleep(60);
        }

        sleep(10); 
    }

    return 0;
}

/************************ Sample Output ******************************
$ ./q30 00 45 /home/daksh/ss_lab/q28
# (program goes into background as a daemon)

# At 00:45 system time → q28 is executed automatically.
*********************************************************************/

