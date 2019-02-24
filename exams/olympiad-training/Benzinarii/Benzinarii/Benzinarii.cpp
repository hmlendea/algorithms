#include "stdafx.h"
#include "stdio.h"

int a[21][21], benz[21], n, m, p;
FILE *f;

void citire()
{
	f = fopen("benzinarii.in", "r");

	fscanf(f, "%d %d %d", &n, &m, &p);

	for (int i = 1; i <= m; i++)
	{
		int x, y;
		fscanf(f, "%d %d", &x, &y);
		
		a[x][y] = a[y][x] = 1;
	}

	for (int i = 1; i <= p; i++)
	{
		int b = 0;
		fscanf(f, "%d", &b);

		benz[b] = 1;
	}

	fclose(f);
}
int dist2noduri(int nod1, int nod2)
{
	int viz[21] = { 0 }, c[21] = { 0 };
	int p, u, k;

	p = u = 1;

	c[p] = nod1;
	viz[nod1] = 1;

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

	return viz[nod2] - 1;
}

int _tmain()
{
	citire();

	FILE *g = fopen("benzinarii.out", "w");

	for (int i = 1; i <= n; i++)
	{
		int min = 873;
		int b = 0;

		for (int j = 1; j < n; j++)
		{
			if (benz[j])
			{
				int d = dist2noduri(i, j);

				if (d < min && d >= 0)
				{
					min = d;
					b = j;
				}
			}
		}

		if (b == 0)
			fprintf(g, "-1 ");
		else
			fprintf(g, "%d ", b);
	}

	fclose(g);

	return 0;
}

