#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int ac ,char **av)
{
    if (ac != 3) {
        write(2, "Usage: ./client <PID> <signal_number>\n", 38);
        return 1;
    }
    pid_t pid = atoi(av[1]);
    int sig = atoi(av[2]);
    if(kill(pid,sig) == -1)
    {
        perror("kill");
        return(1);
    }
    return(0);  
}