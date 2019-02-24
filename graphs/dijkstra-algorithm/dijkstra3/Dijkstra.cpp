#include<stdio.h>

#define INFINIT 9999

int min, np, k, m, n, vi, vf, cost;
int c[20][20], s[20], d[20], prec[20];

FILE *f, *g;

void citire()
{
	int i, j;
	
	f = fopen("Dijkstra.in", "r");
	
	fscanf(f, "%d%d", &n, &m);
	
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			c[i][j] = INFINIT;
		
	for(i=1; i<=n; i++)
		c[i][i] = 0;
	
	for(i=1; i<=m; i++)
	{
		fscanf(f, "%d%d%d",&vi,&vf,&cost);
		c[vi][vf] = cost;
	}
	
	fclose(f);
}

void afisareMatrice()
{
	int i, j;
	
	g = fopen("Dijkstra.out", "w");
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			fprintf(g,"%3d ",c[i][j]);
		fprintf(g,"\n");
	}
	
	fclose(g);
}

void traseu(int x)
{
	if(prec[x]) traseu(prec[x]); 
	printf("%d ", x);
}

void dijkstra()
{
	int i;
	
	s[np] = 1;
	
	for(i=1; i<=n; i++)
	{
		if(c[np][i] != INFINIT && c[np][i] != 0) prec[i] = np;
		d[i] = c[np][i];
	}
	
	do
	{
		min = INFINIT;
		for(i=1; i<=n; i++)
			if(d[i] < min && !s[i])
			{
				min = d[i];
				k = i;
			}
		if(min != INFINIT)
		{
			s[k] = 1;
			for(i=1; i<=n; i++)
			{
				if(!s[i] && d[i] > d[k] + c[k][i])
				{
					d[i] = d[k] + c[k][i];
					prec[i] = k;
				}
			}
		}
	} while(min != INFINIT);
	
	for(i=1; i<=n; i++)
	{
		if(d[i] != 0)
		{
			if(d[i] == INFINIT) printf("\nDrumul [%d - %d] nu exista",np,i);
			else 
			{	
				printf("\nDrumul [%d - %d] = %d. Traseul: ", np, i, d[i]);
				traseu(i);
			}
		}
	}
}

int main()
{
	citire();
	afisareMatrice();
	printf("Nodul de pornire: ");
	scanf("%d", &np);
	dijkstra();
	return 0;
}
