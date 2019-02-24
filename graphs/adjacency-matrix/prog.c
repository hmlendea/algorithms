#include <stdio.h>

int n, m;
int a[30][30];

void citire ();
void scriere ();

int main (int argc, char *argv[])
{
    citire();
    scriere();

    return 0;
}

void citire ()
{
    FILE *f;
    int i, v1, v2, c;

    f = fopen ("graf.in", "r");
    fscanf (f, "%d %d", &n, &m);

    for (i = 0; i < m; i++)
    {
        fscanf (f, "%d %d %d", &v1, &v2, &c);
        a[v1][v2] = c;
    }

    fclose (f);
}

void scriere ()
{
    int i, j;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf ("%d ", a[i][j]);
        printf ("\n");
    }
}

