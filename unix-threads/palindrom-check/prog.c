#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <error.h>

// Scrieti un program care primeste ca argumente numere.
// Pentru fiecare argument din linia de comanda creeaza un thread care verifica daca
// numarul este palindrom, si, in caz afirmativ incrementeaza o suma globala (in thread).
//
// Un numar este palindrom daca este egal cu oglindirea lui.
// De ex 1234321 este palindrom, 1221 este palindrom.

int count;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void* func (void* param)
{
    int nr = atoi((char*) param);
    int nr1 = nr;
    int nr2 = 0;

    while (nr != 0)
    {
        nr2 = nr2 * 10 + nr % 10;
        nr /= 10;
    }

    if (nr1 == nr2)
    {
        pthread_mutex_lock (&m);
        count += 1;
        pthread_mutex_unlock (&m);
    }
}

int main(int argc, char *argv[])
{
    int i;
    pthread_t t[30];

    for (i = 1; i < argc; i++)
        if (pthread_create (&t[i], NULL, func, argv[i]) < 0)
        {
            perror ("Error creating thread");
            exit (1);
        }

    for (i = 1; i < argc; i++)
        pthread_join (t[i], NULL);

    printf ("Result: %d palindroms\n", count);

    return 0;
}

