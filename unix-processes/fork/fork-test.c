#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>

#include <sys/types.h>

int main(int argc, char *argv[])
{
    int p = fork ();

    if (p > 0)
        printf ("We are in the parent (Current PID %d, Child PID %d)\n", getpid(), p);
    else if (p == 0)
        printf ("We are in the child (Current PID %d, Parent PID %d)\n", getpid(), getppid());
    else
    {
        perror ("Error forking");
        exit (1);
    }

    printf ("Print test (PID %d)\n", getpid());

    return 0;
}

