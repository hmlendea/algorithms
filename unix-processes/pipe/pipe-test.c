#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <sys/types.h>

// Sa se implementeze un proces care primeste ca argumente numere.
// Pentru fiecare argument creeaza alt proces care va verifica daca argumentul este un numar par.
// Procesul principal va afisa rezultat primit de la procesele fiu pentru fiecare argument.
// Comunicarea intre procese se va face cu pipe.

int main(int argc, char *argv[])
{
    int i, nr = 200, rez;

    printf ("argc=%d\n", argc);

    for (i = 1; i < argc; i++)
    {
        printf ("%d\n", atoi ( (char*)argv[i]));

        int f = fork ();
        int pr[2], pw[2];

        if (pipe (pr) < 0)
        {
            perror ("Error creating read-pipe");
            exit (1);
        }

        if (pipe (pw) < 0)
        {
            perror ("Error creating write-pipe");
            exit (2);
        }

        if (f < 0)
        {
            perror ("Error creating fork");
            exit (3);
        }
        else if (f == 0) // Inside the CHILD
        {
            printf ("CHILD MAN\n");
            close (pr[1]);

            if (read (pr[0], &nr, sizeof (int)) < 0)
            {
                perror ("Error pipe-reading");
                exit (4);
            }

            printf ("received %d\n", nr);
            close (pr[0]);

            rez = 1;
            if (nr % 2 != 0)
                rez = 0;
            printf("%d, %d\n", nr, rez);

            close (pw[0]);
            printf ("child sending %d\n", rez);
            if (write (pw[1], &rez, sizeof (int)) < sizeof (int))
            {
                perror ("Error pipe-writing");
                close (pw[1]);
                exit (5);
            }
        }
        else // Inside the PARENT
        {
            close (pr[0]);
            printf ("PARENT MAN\n");

            nr = atoi (argv [i]);

            printf ("sending %d\n", nr);

            if (write (pr[1], &nr, sizeof (int)) < 0)
            {
                perror ("Error pipe-writing");
                close (pr[1]);
                exit (6);
            }

            close (pw[1]);
            printf("sasa\n");
            if (read (pw[0], &rez, sizeof (int)) < sizeof (int))
            {
                perror ("Error pipe-reading");
                close (pw[0]);
                exit (7);
            }

            printf ("nr=%d rez=%d\n", nr, rez);
            close (pw[0]);
            //exit (0);
        }
    }

    return 0;
}

