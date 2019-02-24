#include <stdio.h>

#define INF 32768

int c[21][21], s[21], prec[21], d[21];
int n, m;

void citire ()
{
    FILE *f = fopen ("graf.in", "r");
    int i, j;

    fscanf (f, "%d %d", &n, &m);

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            c[i][j] = INF;

    for (i = 1; i <= n; i++)
        c[i][i] = 0;

    for(i = 1; i <= m; i++)
    {
        int x, y, z;
        fscanf (f, "%d %d %d", &x, &y, &z);
        c[x][y] = z;
    }

    fclose (f);
}

void afisare ()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (c[i][j] == INF)
                printf ("* ");
            else
                printf ("%d ", c[i][j]);

        printf ("\n");
    }
}

void traseu (int x)
{
	if (prec[x])
        traseu (prec[x]);

	printf ("%d ", x);
}

void dijkstra (int np)
{
    int i, j, k, min;

    s[np] = 1;

    for (i = 1; i <= n; i++)
    {
        d[i] = c[np][i];

        if (!s[i] && d[i] != 0 && d[i] != INF)
            prec[i] = np;
    }

    do
    {
        min = INF;

        for (i = 1; i <= n; i++)
            if (!s[i] && d[i] < min)
            {
                min = d[i];
                k = i;
            }

        if (min != INF)
        {
            s[k] = 1;

            for (i=1; i<=n; i++)
                if (!s[i] && d[i] > d[k] + c[k][i])
                {
                    d[i] = d[k] + c[k][i];
                    prec[i] = k;
                }
        }
    } while (min != INF);

    for (i = 1; i <= n; i++)
        if(d[i] != 0 && d[i] != INF)
        {
            printf ("dist(%d,%d) = %d ::: Traseu: ", np, i, d[i]);
            traseu (i);
            printf ("\n");
        }
}

int main ()
{
    int np;

    citire ();
    afisare ();

    printf ("np=");
    scanf ("%d", &np);
    
    dijkstra (np);

    return 0;
}

