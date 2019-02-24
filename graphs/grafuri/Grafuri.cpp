#include <cstdio>
using namespace std;

#define INF 99999
int a[21][21], cnx[21], c[21], viz[21];
int n, m, comp, p, u;

void citire()
{
    FILE *f = fopen("graf.in", "r");
    int i, j;

    fscanf(f, "%d %d", &n, &m);

    for(i=1; i<=m; i++)
    {
        int x, y, z;
        fscanf(f, "%d %d", &x, &y);

        a[x][y] = 1;
        a[y][x] = 1;
    }

    fclose(f);
}

void conex(int i)
{
    int j;

    for(j=1; j<=n; j++)
        if(a[i][j] && !cnx[j])
        {
            cnx[j] = comp;
            conex(j);
        }
}

void parcurgereL(int np)
{
    int i, j, x;

    p = 1;
    u = 1;

	c[p] = np;
	viz[np] = 1;

	while (p <= n && u < n)
	{
		x = c[p];

		for (int i = 1; i <= n; i++)
            if (a[x][i] == 1 && !viz[i])
            {
                u += 1;
                c[u] = i;
                viz[i] = viz[x] + 1;
            }
		p += 1;
	}
}

int grad(int nod)
{
    int gr = 0;

    for(int i=1; i<=n; i++)
        gr += a[nod][i];

    return gr;
}

int main()
{
    int i, np;

    citire();

    for(i=1; i<=n; i++)
        if(!cnx[i])
        {
            comp++;
            cnx[i]=comp;
            conex(i);
        }

    for(i=1; i<=n; i++)
        printf("nodul %d apartine componentei %d\n", i, cnx[i]);

    printf("np="); scanf("%d", &np);
    parcurgereL(np);

    printf("Parcurgerea in latime incepand din nodul %d: ", np);
    for(i=1; i<=n; i++)
        printf("%d ", c[i]);
    printf("\n");

    printf("Lantul minim din nodul %d in fiecare nod: ", np);
    for(i=1; i<=n; i++)
        printf("%d ", viz[i]-1);
    printf("\n");

    printf("Alege un nod de la 1 la %d: ", n); scanf("%d", &np);
    printf("Gradul nodului %d este %d\n", np, grad(np));

    return 0;
}
