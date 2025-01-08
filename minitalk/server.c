#include <unistd.h>
#include <stdio.h>
#include <signal.h>


void handler_signal(int sig)
{
    if (sig == SIGUSR1)
    {
        write(1, "This is the first signal\n", 25);
    }
    else if (sig == SIGUSR2)
    {
        write(1, "This is the second signal\n", 26);
    }
}

int main()
{
    signal(SIGUSR1,handler_signal);
    signal(SIGUSR2,handler_signal);

    printf("The PID of the server is %d\n", getpid());
    while(1)
    {
       
    }
}