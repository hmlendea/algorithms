/* Varianta 1 Subiectul 3 Exercitiul 3

Fisierul text bac.txt contine, pe o singura linie, cel mult 1000 de numere naturale nenule 
cu cel mult 4 cifre fiecare, numerele fiind separate prin câte un spatiu. Scrieti un program 
C/C++ care citeste de la tastatura un numar natural nenul n (n<=999) si numerele din fisierul 
bac.txt si care afiseaza pe ecran, separate prin câte un spatiu, toate numerele din fisier 
care sunt divizibile cu n. Daca fisierul nu contine niciun astfel de numar, atunci se va afisa 
pe ecran mesajul NU EXISTA. 

Exemplu: daca fisierul bac.txt contine numerele: 3 100 40 70 25 5 80 6 3798, 
pentru n=10 atunci pe ecran se va afisa: 100 40 70 80
*/

#include<stdio.h>

int main()
{
	FILE *f=fopen("bac.txt", "r");
	int n;
	int ok=0;
	
	printf("n=");
	scanf("%d", &n);
	
	while(!feof(f))
	{
		long x;
		fscanf(f, "%ld", &x);
		
		if(x%n==0)
		{
			printf("%ld ", x);
			ok=1;
		}
	}
	
	if(ok==0)
		printf("NU EXISTA");
	
	return 0;
}
