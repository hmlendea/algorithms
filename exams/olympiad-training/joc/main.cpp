#include<stdio.h>

int n, m;
int maria, ion;
int a[101][101], b[101][101];

FILE *f, *g;

void citire()
{
	int i, j;
	
	f = fopen("joc.in", "r");
	
	fscanf(f, "%d %d", &n, &m);
	
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
		{
			fscanf(f, "%d ", &a[i][j]);
			b[i][j] = a[i][j];
		}
	}
	
	fclose(f);
}

void sumaMaria()
{
	int i, j;
	
	for(i=n; i>=1; i--)
		a[i][m] += a[i+1][m];
	for(j=m; j>=1; j--)
		a[n][j] += a[n][j+1];
	
	for(i=n-1; i>=1; i--)
	{
		for(j=m-1; j>=1; j--)
		{
			if(a[i+1][j] >= a[i][j+1]) a[i][j] += a[i+1][j];
			else a[i][j] += a[i][j+1];
		}
	}
	
	maria = a[1][1];
}

void sumaIon()
{
	int i, j;
	
	for(i=n; i>=1; i--)
		b[i][1] += b[i+1][1];
	for(j=1; j<=m; j++)
		b[n][j] += b[n][j-1];
	
	for(i=n-1; i>=1; i--)
	{
		for(j=2; j<=m; j++)
		{
			if(b[i][j-1] >= b[i-1][j]) b[i][j] += b[i][j-1];
			else b[i][j] += b[i-1][j];
		}
	}
	
	ion = b[1][m];
}

void afisare()
{
	g = fopen("joc.out", "w");
	
	if(maria > ion) fprintf(g, "1 %d", maria);
	else
	{
		if(maria < ion) fprintf(g, "2 %d", ion);
		else fprintf(g, "3 %d", ion);
	}
	
	fclose(g);
}

int main()
{
	citire();
	sumaMaria();
	sumaIon();
	afisare();
	return 0;
}