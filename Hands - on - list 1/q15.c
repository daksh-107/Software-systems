/************************** 
Name: q15.c
Author: Daksh Minda
Description: Program to display the environment variables of the user using environ
Date: 01/09/25
********************************************************************/

#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main() {
    char **env = environ;

    printf("Environment variables:\n\n");
    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}

/************************ Sample Output ******************************
$ ./q15
Environment variables:

USER=daksh
DISPLAY=:0
SHLVL=2
XDG_SESSION_ID=c1
XDG_RUNTIME_DIR=/run/user/1001
WSLENV=
XDG_DATA_DIRS=/usr/local/share:/usr/share:/var/lib/snapd/desktop
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
MAIL=/var/mail/daksh
HOSTTYPE=x86_64
PULSE_SERVER=unix:/mnt/wslg/PulseServer
OLDPWD=/home/iiitb
_=./q15
...
*********************************************************************/

