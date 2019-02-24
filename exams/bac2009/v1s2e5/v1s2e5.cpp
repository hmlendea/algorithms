/* Varianta 1 Subiectul 2 Exercitiul 5

Scrieti un program C/C++ care citeste de la tastatura doua numere naturale nenule n si m 
(2<=m<=10, 2<=n<=10) si care construieste în memorie si apoi afiseaza o matrice A cu n linii 
(numerotate de la 1 la n) si m coloane (numerotate de la 1 la m) cu proprietatea ca fiecare 
element Aij memoreaza cea mai mica dintre valorile indicilor i si j (1<=i<=n, 1<=j<=m). 
Matricea se va afisa pe ecran, câte o linie a matricei pe câte o linie a ecranului, elementele 
fiecarei linii fiind separate prin câte un spatiu.

Exemplu: pentru n=4 si m=5 se va afisa matricea alaturata. 
 1 1 1 1 1 
 1 2 2 2 2 
 1 2 3 3 3 
 1 2 3 4 4 
*/

#include<stdio.h>

int main()
{
	int n, m, i, j;
	int a[11][11];
	
	printf("n="); scanf("%d", &n);
	printf("m="); scanf("%d", &m);
	
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			if(i<j)
				a[i][j]=i;
			else
				a[i][j]=j;
	
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	
	return 0;
}