#include<stdio.h>

int v[873],n,i,x;

void intro()
{
	printf("=======================\n");
	printf("--- Cautarea Binara\n");
	printf("=======================\n\n\n");
}

void citire()
{
	int i;

	// Lungimea vectorului
	printf("Introduceti lungimea sirului: ");
	scanf("%d",&n);

	// Elementele vectorului
	printf("Introduceti elementele sirului:\n");
	for(i=0;i<n;i++)
	{
		printf("v[%d] = ",i);
		scanf("%d",&v[i]);
	}

	// Elementul de cautat
	printf("Introduceti elementul de cautat: ");
	scanf("%d",&x);
}

int Cautare_Binara(int p, int q)
{
	int m;

	if(p>q) return -1;
	else
	{
		m=(p+q)/2;
		if(x==v[m]) return m;
		else if(x<v[m]) return Cautare_Binara(p,m-1);
		else return Cautare_Binara(m+1,q);
	}
}

int main()
{
	intro();
	citire();

	int p=Cautare_Binara(0,n-1);
	if(p==-1) printf("'%d' nu a fost gasit in vector!\n",x);
	else printf("'%d' a fost gasit in vector pe pozitia a %d-a\n",x,p);

	return 0;
}
