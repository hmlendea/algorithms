// Pentru un n dat (5<n<=15) sa se creeze n procese astfel.
// Programul principal creeaza un proces. Acest proces creeaza la randul lui inca un proces
// si tot asa pana cand s-au creat n procese.
// Fiecare proces comunica cu fiul lui folosind cate un canal pipe.
// Parintele genereaza un numar aleator intre 1000 si 10000 si el initiaza jocul.
// Jocul incepe doar dupa ce toate procesele sau creat.
// Fiecare proces scade din valoarea primita o valoare intre 10 si 20 (generata aleator) si trimite
// numarul obtinut fiului propriu. Ultimul fiu nu trimite mai departe.
// Acesta doar dipareste numarul primit si jocul se termina.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

typedef struct number_message
{
    int length;
    int number;

} NumberMessage;

void my_read(int f, int *t, int n)
{
    int *p;
    int i, c;

    for (p = t, c = n;;)
    {
        i = read(f, p, c);

        if (i == c)
            return;

        c -= i;
        p += i;
    }
}

void my_write(int f, int *t, int n)
{
    int *p;
    int i, c;

    for (p = t, c = n; c;)
    {
        i = write(f, p, c);

        if (i == c)
            return;

        c -= i;
        p += i;
    }
}

void read_message(int canal, NumberMessage* msg)
{
    my_read(canal, &msg->length, sizeof(int));
    my_read(canal, (int*) (&msg->number), msg->length);
}

void write_message(int canal, NumberMessage* msg)
{
    my_write(canal, &msg->length, sizeof(int));
    my_write(canal, (int*) &msg->number, msg->length);
}

int random_number(int min, int max)
{
    if (min == max)
        return min;
    else if (min > max)
    {
        int aux = min;
        min = max;
        max = aux;
    }

    srand (time(NULL));
    return min + rand() % (max + 1 - min);
}

int main(void)
{
    int p[2];
    int f, nr, i;
    NumberMessage msg;

    pipe (p);
    printf ("Processes count: \n");
    scanf ("%d", &nr);

    // Validate the number of processes
    while (nr <= 5 || nr > 15)
    {
        printf("The processes count must be between (5, 15]\n");
        scanf("%d", &nr);
    }

    f = fork();

    if (f == -1)
    {
        perror ("Forking error");
        exit(0);
    }
    else if (f > 0)
    {
        msg.number = random_number (1000, 10000);
        msg.length = sizeof (int);

        write_message (p[1], &msg);

        close(p[0]);
        close(p[1]);
    }
    else
    {
        for (i = 0; i < nr; i++)
        {
            f = fork();

            if (f < 0)
            {
                perror("Eroare fork");
                exit(1);
            }
            else if (f == 0)
            {
                read_message (p[0], &msg);
                msg.number = msg.number - random_number(10, 20);
                write_message (p[1], &msg);

                close (p[0]);
                close (p[1]);

                if (i + 1 == nr)
                   printf ("The result is %d\n", msg.number);

                exit(1);
            }
            wait(0);
        }
        exit(1);
    }
    wait(0);

    return 0;
}

