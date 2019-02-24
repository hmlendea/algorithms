#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <error.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

// Scrieti un program care pentru fiecare argument din linia de comanda creeaza un thread care
// verifica daca argumentul dat este un fisier sau un folder si in functie de rezultat
// va creste una din variabilele globale nr_files sau nr_folders
// Daca nu este nici fisier nici folder, nu face nimic
// La sfarsit, programul principal afiseaza numarul de fisiere si foldere.

int nr_files;
int nr_folders;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void* func (void* param)
{
    char* path = (char*)param;
    struct stat s;
    int i;

    i = stat (path, &s);

    if (i == -1)
    {
        if (errno == ENOENT)
        {
            // Does not exist
        }
        else
        {
            perror ("Error at stat");
            exit (1);
        }
    }
    else
    {
        pthread_mutex_lock (&m);
        if (S_ISDIR (s.st_mode))
            nr_folders += 1;
        else
            nr_files += 1;
        pthread_mutex_unlock (&m);
    }
}

int main(int argc, char *argv[])
{
    int i;
    pthread_t t[20];

    for (i = 1; i < argc; i++)
        if (pthread_create (&t[i], NULL, func, argv[i]) < 0)
        {
            perror ("Error creating thread");
            exit (1);
        }

    for (i = 1; i < argc; i++)
        pthread_join (t[i], NULL);

    printf ("Result: %d files and %d folders\n", nr_files, nr_folders);

    return 0;
}

