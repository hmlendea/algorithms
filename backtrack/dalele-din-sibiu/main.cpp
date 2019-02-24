#include<stdio.h>
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};

int col[4] = {1,2,3,4};
int a[20][20],t[20][20];

int pas, n, m, Solutia, s1, s2;

FILE *Intrare;
FILE *Iesire = fopen( "Iesire.TXT","w" );
 
void Citire()
{
	Intrare = fopen( "Intrare.TXT","r" );
	fscanf( Intrare, "%d %d", &n, &m );
	fclose( Intrare );
}

void Tiparire()
{
	Solutia++;
	
	if( Solutia<10 )
		fprintf( Iesire,"Solutia numarul 000%d:\n",Solutia );
	
	else if( Solutia<100 && Solutia>=10 )
		fprintf( Iesire,"Solutia numarul 00%d:\n",Solutia );
	
	else if( Solutia<1000 && Solutia>=100 )
		fprintf( Iesire,"Solutia numarul 0%d:\n",Solutia );
	
	else //Orice altceva
		fprintf( Iesire,"Solutia numarul %d:\n",Solutia );
	
	for( int i=0; i<n; i++ )
	{
		for( int j=0; j<m; j++ )
			fprintf( Iesire, "%d", t[i][j] );
		fprintf( Iesire, "\n" );
	}
	fprintf( Iesire, "\n" );
	
	if( Solutia%873==0)
		printf(".\n");
}

int nu( int i,int j,int cul )
{
	int ii, jj, k;
	for( k=0; k<8; k++ )
	{
		ii = i+dx[k];
		jj = j+dy[k];
		
		if( ii>=0 && ii<n && jj>=0 && jj<m )
			if( t[ii][jj]==cul )
				return 0;}
	return 1;
}	
	
void Traseu( int i,int j )
{
	int ii,jj,k,cc;
	for( k=0; k<8; k++ )
	{
		ii=i+dx[k];
		jj=j+dy[k];
		if( ii>=0 && ii<n && jj>=0 && jj<m )
		if( t[ii][jj]==0 )
		{
			for( cc=0;cc<4;cc++ )
			{
				if( nu( ii,jj,col[cc] ) )
				{
					t[ii][jj]=col[cc];
					pas++;
					if( pas==n*m )
						Tiparire();
					else 
						Traseu( ii,jj );
					t[ii][jj]=0;
					pas--;
				}
			}
		}
	}
}

int main()
{
	printf("Se citesc dimensiunile matricii...\n");
	Citire();
	pas=1;
	printf("Se calculeaza solutiile... (Poate sa dureze destul de mult)\n");
	for( int i=1; i<=4; i++ )
	{
		t[0][0]=i;
		Traseu( 0,0 );
	}
	fclose( Iesire );
	printf("Sfarsit. Solutiile au fost tiparite in 'Iesire.TXT'.");
	return 0;
}
