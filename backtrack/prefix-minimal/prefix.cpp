#include<stdio.h>
int n,t[10][10],dx[4]={-1,0,1,0},dy[4]={0,1,0,-1},max,sol[10][10];
char a[10][10],cuv[10];
FILE *f=fopen("prefix.in","r");
FILE *g=fopen("prefix.out", "w");
void citire()
{ int i,j;
	fscanf(f,"%d\n",&n);
	for(i=0;i<n;i++)
		{for(j=0;j<n;j++)
			fscanf(f,"%c",a[i][j]);
			fscanf(f,"\n");
		}
		fscanf(f,"%s",&cuv);
		fclose(f);
}
void salvare()
{ int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			sol[i][j]=t[i][j];
}
void tipar()
{ int i,j;
	for(i=0;i<max;i++)
		fprintf(g,"%c",cuv[i]);
		fprintf(g,"\n");
		for(i=0;i<n;i++)
		{ for(j=0;j<n;j++)
			fprintf(g,"%d",sol[i][j]);
			fprintf(g,"\n");
		}
}
void traseu(int i, int j , int pas)
{ int ii,jj,k;
for(k=0;k<4;k++)
	ii=i+dx[k];
	jj=j+dy[k];
	if(ii>=0&&ii<=n&&jj>=0&&jj<=n)
	{	if(a[ii][jj]==cuv[pas-1]&&t[ii][jj]==0&&pas<strlen(cuv))
		{ t[ii][jj]=pas;
		if(pas>max)
		{ max=pas;
		 salvare();
		}
		t[ii][jj]=0;
		}
	}
}
int main()
{ cotore();
	int i,j;
	for(i=0;i<n;i++)
		{for(j=0;j<n;j++)
			if(a[i][j]==cuv[0]);
			{ if(max==0)
				max=1;
				t[i][j]=1;
				traseu(i,j,2);
				t[ii][jj]=0;
			}
		}
		tipar();
return 0;
}