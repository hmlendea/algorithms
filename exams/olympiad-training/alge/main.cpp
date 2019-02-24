#include<stdio.h>

// Ce mai am de facut:
//-sa tin minte pasii prin care trece sub forma de: i, j, k
//-sa tin minte doar cel mai scurt traseu
//-sa rezolv treaba cu lg, lungimea algei (probabil ca merge in sus???)

int dx[6] = {-1,0,1,0,0,0}; // Directiile pt X
int dy[6] = {0,1,0,-1,0,0}; // Directiile pt Y
int dk[6] = {0,0,0,0,-1,1}; // Directiile pt K

int acvariu[35][35][35], t[35][35][35]; // Matricile pt Acvariu si pt Traseu
int n, ng, sol; // Celelalte variabile

FILE *in;
FILE *out=fopen("alge.out", "w");

void citire()
{
	in=fopen("alge.in", "r");
	
	fscanf(in, "%d%d", &n, &ng);
	
	int i,j,k,lg;
	
	for(int h=1; h<=ng ; h++)
	{
		fscanf(in, "%d%d%d%d", &i, &j, &k, &lg);
		
		for(j=j;j<n;j++)
			acvariu[i][j][k] = 1;
	}
	
	fclose(in);
}

void tiparire(int pas)
{
	sol++;
	fprintf(out, "Solutia %d:\n", sol);
	
	//////////////////////
	
	fprintf(out, "'========='\n");
}

void traseu(int i, int j, int k, int pas)
{
	int ii, jj, kk, dir;
	for(dir=1; dir<=6; dir++)
	{
		ii = i+dx[dir];
		jj = j+dy[dir];
		kk = k+dk[dir];
		
		if(ii>=1 && ii<=n && jj>=1 && jj<=n && kk>=1 && kk<=n)
		{
			if(acvariu[ii][jj][kk]==0 && t[ii][jj][kk]==0)
			{
				t[ii][jj][kk] = pas;
				
				////////////////////////////
				
				if(ii==3 && jj==3 && kk==3)
					tiparire(pas);
				else
					traseu(ii, jj, kk, pas+1);
				t[ii][jj][kk] = 0;
			}
		}
	}
}

int main()
{
	citire();
	
	t[1][1][1] = 1;
	
	traseu(1, 1, 1, 2);
	fclose(out);
	return 0;
}
