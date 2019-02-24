/* Varianta 1 Subiectul 3 Exercitiul 4

Subprogramul sub, cu trei parametri, primeste prin intermediul parametrilor: 
– v un tablou unidimensional cu cel mult 100 de componente ce memoreaza numere 
întregi de cel mult 4 cifre fiecare; 
– n un numar natural nenul mai mic sau egal cu 100 ce reprezinta numarul efectiv de 
componente ale tabloului primit prin intermediul parametrului v; 
– a un numar întreg cu cel mult 4 cifre. 
Subprogramul sub returneaza numarul componentelor tabloului primit prin intermediul 
parametrului v ale caror valori sunt egale cu valoarea parametrului a. 

Exemplu: pentru valorile n=5, v=(1,21,9,21,403), a=21 ale parametrilor, în urma 
apelului, subprogramului sub va returna valoarea 2. 

a) Scrieti definitia completa a subprogramului sub. (4p.) 
b) Scrieti un program C/C++ care sa citeasca de la tastatura un numar natural nenul n 
(n<=100) si n numere întregi, fiecare având cel mult 4 cifre, si care, folosind apeluri utile ale 
subprogramului sub, sa afiseze pe ecran mesajul DA daca oricare doua dintre cele n 
numere citite sunt distincte doua câte doua, sau mesajul NU în caz contrar. 

Exemplu: pentru n=6 si cele n numere citite de la tastatura: 47 183 69 8 134 -56 
se va afisa pe ecran mesajul DA
*/

#include<stdio.h>

int sub(int v[100], int n, int a)
{
	int nr=0;
	for(int i=0; i<n; i++)
		if(v[n]==a)
			nr+=1;
	return nr;
}

int main()
{
	int n;
	int ok=1;
	int ult=0;
	
	printf("n=");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
	{
		int x;
		
		printf("numar%d=", i+1);
		scanf("%d", &x);
		
		if(i>=1 && ok==0)
		{
			if(sub({x, ult}, 2, ult)==1)
				ok=0;
		}
		
		ult=x;
	}
	
	if(ok==1)
		printf("DA");
	else
		printf("NU");
	
	return 0;
}
