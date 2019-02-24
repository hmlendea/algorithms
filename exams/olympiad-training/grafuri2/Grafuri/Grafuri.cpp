#include "stdafx.h"
#include "stdio.h"

int a[21][21], g[21], cnx[21];
int n, m, nr;
FILE *f;

void citire()
{
	f = fopen("graf.in", "r");

	fscanf(f, "%d", &n);
	fscanf(f, "%d", &m);

	for (int i = 1; i <= m; i++)
	{
		int x, y;

		fscanf(f, "%d %d", &x, &y);

		a[x][y] = 1;
		a[y][x] = 1;
	}

	fclose(f);
}
int grad(int nod)
{
	int gr = 0;

	for (int i = 1; i <= n; i++)
		if (a[i][nod] == 1)
			gr += 1;

	return gr;
}
void conex(int i)
{
	for (int j = 1; j <= n; j++)
		if (a[i][j] && !cnx[j])
		{
			cnx[j] = nr;
			conex(j);
		}
}
void afisareMatrice()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d ", a[i][j]);

		printf("\n");
	}
}
void afisareCompConexe()
{
	for (int i = 1; i <= n; i++)
	if (!cnx[i])
	{
		nr += 1;
		cnx[i] = nr;
		conex(i);
	}
	printf("Comp: [");
	for (int i = 1; i <= n; i++)
	{
		printf("%d", cnx[i]);
		if (i < n)
			printf(" ");
	}
	printf("]\nNodul: ");
	for (int i = 1; i <= n; i++)
		printf("%d ", i);
	printf("\n");
}
void parcurgereBF(int np)
{
	int viz[20] = { 0 }, c[20] = { 0 };
	int p, u, x;

	p = u = 1;

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
			viz[i] = 1;
		}
		p += 1;
	}

	printf("Parcurgerea BF (in latime), pornind din %d: [", np);
	for (int i = 1; i <= n; i++)
	{
		printf("%d", c[i]);
		if (i < n)
			printf(", ");
	}
	printf("]\n");
}

void afisareDistante(int np)
{
	int viz[21] = { 0 }, c[21] = { 0 };
	int p, u, k;

	p = u = 1;

	c[p] = np;
	viz[np] = 1;

	while (p <= u)
	{
		k = c[p];

		for (int i = 1; i <= n; i++)
		if (a[k][i] && !viz[i])
		{
			u += 1;
			c[u] = i;
			viz[i] = viz[k] + 1;
		}

		p += 1;
	}
	for (int i = 1; i <= n; i++)
		viz[i] -= 1;

	printf("Distantele dintre nodul %d si celelalte noduri:\n", np);

	printf("Dist:  ");
	for (int i = 1; i <= n; i++)
		printf("%d ", viz[i]);
	printf("\n");

	printf("Nodul: ");
	for (int i = 1; i <= n; i++)
		printf("%d ", i);
	printf("\n");
}

int _tmain()
{
	int nod;

	citire();
	afisareMatrice();
	afisareCompConexe();
	parcurgereBF(1);

	printf("nod="); scanf("%d", &nod);
	printf("Gradul nodului %d este egal cu %d!\n", nod, grad(nod));

	return 0;
}

