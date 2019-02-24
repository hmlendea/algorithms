#include<stdio.h>
int n, m, y, x, i;
int a[10][10], viz[100], c[100];
FILE *f=fopen("graf.in", "r");

void Citire()
{
	fscanf(f, "%d %d ",&n,&m);
	for(int i=1;i<=m;i++)
	{
		fscanf(f,"%d %d", &x,&y);
		a[x][y]= a[y][x]=1;
	}
}

int main()
{
	int np, p, u, ok=0;
	Citire();
	scanf("%d",&np);
	c[1]=np;
	viz[np]=1;
	p=u=1;
	while(p<=u && !ok)
	{
		x = c[p];
		for(int i=1;i<=n;i++)
			if(a[x][i] && !viz[i])
			{
				u++;
				c[u] = i;
				viz[i] = 1;
				if(u==n)
				ok=1;
			}
	p++;
	}
	for(int i=1;i<=u;i++)
		printf("%d",c[i]);
return 0;
}