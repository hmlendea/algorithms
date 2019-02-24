#include<stdio.h>

int dx[4]={-1,0,1,0}; // Directiile pt X
int dy[4]={0,1,0,-1}; // Directiile pt Y
int lab[20][20], t[20][20]; // Matricile pt Labirint si pt Traseu
int l,c,n,m,sol; // Celelalte variabile

FILE *f=fopen("lab.in","r");
FILE *g=fopen("lab.out","w");

void citire()
{
	fscanf(f,"%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			fscanf(f,"%d",&lab[i][j]);
	fscanf(f,"%d%d",&l,&c);
	fclose(f);
}

void tiparire()
{
	int i,j;
	sol++;
	fprintf(g,"sol = %d:\n",sol);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			fprintf(g,"%d ",t[i][j]);
		fprintf(g,"\n");
	}
}

void traseu(int i, int j, int pas)
{
	int ii,jj,k;
	for(k=1;k<=4;k++)
	{
		ii=i+dx[k];
		jj=j+dy[k];
		
		if(ii>=1 && ii<=n && jj>=1 && jj<=m)
		{
			if(lab[ii][jj]==1 && t[ii][jj]==0)
			{
				t[ii][jj]=pas;
				if(ii==1 || ii==n || jj==1 || jj==m)
					tiparire();
				else
					traseu(ii,jj,pas+1);
				t[ii][jj]=0;
}	}	}	}

int main()
{
	citire();
	t[l][c]=1;
	traseu(l,c,2);
	fclose(g);
	return 0;
}