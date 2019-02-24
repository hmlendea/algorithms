#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <sys/types.h>

// (0)
//  | \
// (1)(2)
//      \
//      (3)

int main(int argc, char *argv[])
{
    int p = fork();

    if (p == -1)
    {
        perror ("Error creating P1");
        exit (1);
    }
    else if (p == 0)
        printf ("We're in P1\n");
    else
    {
        printf ("We're in P0\n");
        p = fork();

        if (p == -1)
        {
            perror ("Error creating P2");
            exit (2);
        }
        else if (p == 0)
        {
            printf ("We're in P2\n");
            p = fork ();

            if (p == -1)
            {
                perror ("Error creating P3");
                exit (3);
            }
            else if (p == 0)
                printf ("We're in P3\n");
        }
    }

    return 0;
}
