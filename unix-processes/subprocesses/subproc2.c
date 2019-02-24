#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int i, p, n;

    printf ("This algorithm will create a process structure resembling a perfect binary tree with n levels\n");
    printf ("n = ");
    scanf ("%d", &n);

    for (i = 0; i < n; i++)
    {
        p = fork ();
        wait (0);
        if (p < 0)
        {
            perror ("Error forking");
            exit (1);
        }
        else if (p == 0)
            printf ("PID=%d, Level=%d\n", getpid (), i);
    }

    return 0;
}
