// Pe o tabla de sah de dimensiunea n se afla un cal CHUCK NORRIS in pozitia X0:Y0
//
// Afisati toate posibilitatile calului de a parcurge toata tabla, fara a trece de 2 ori
// prin aceeasi pozitie.

#include<stdio.h>

int dx[8]={-2,-1,1,2,2,1,-1,-2}; // Directiile pt X
int dy[8]={-1,-2,-2,-1,1,2,2,1}; // Directiile pt Y
int t[20][20]; // Matricea pt Traseu
int l,c,n,sol; // Celelalte variabile

FILE *f=fopen("cal.in","r");
FILE *g=fopen("cal.out","w");

void citire()
{
	fscanf(f,"%d",&n);
	fscanf(f,"%d %d",&l,&c);
	fclose(f);
}

void tiparire()
{
	int i,j;
	sol++;
	fprintf(g,"sol %d:\n",sol);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			fprintf(g,"%d ",t[i][j]);
		fprintf(g,"\n");
	}
}

void traseu(int i, int j, int pas)
{
	int ii,jj,k;
	for(k=0;k<8;k++)
	{
		ii=i+dx[k];
		jj=j+dy[k];
		if(ii>=1 && ii<=n && jj>= 1 && jj<=n)
		{
			if(t[ii][jj]==0)
			{
				t[ii][jj]=pas;
				if(pas==n*n)
					tiparire();
				else
					traseu(ii,jj,pas+1);
				t[ii][jj]=0;
			}
		}
	}
}

int main()
{
	citire();
	t[l][c]=1;
	traseu(l,c,2);
	fclose(g);
	return 0;
}