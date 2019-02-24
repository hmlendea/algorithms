#include<stdio.h>

int v[873],n,i;

void intro()
{
	printf("=======================\n");
	printf("--- Quicksort II\n");
	printf("=======================\n\n\n");
}

void citire()
{
//////Lungimea vectorului
	printf("Introduceti lungimea sirului: ");
	scanf("%d",&n);
//////Elementele vectorului
	printf("Introduceti elementele sirului:\n");
	for(i=0;i<n;i++)
	{
		printf("v[%d] = ",i);
		scanf("%d",&v[i]);
	}
}

void afisare()
{
	printf("\n\n\nSirul dupa sortare:");
	for(i=0;i<n;i++)
	{
		printf("%d ",v[i]);
	}
}

int divide(int p, int q)
{
	int i, j, x;
	
	x=v[p];
	i=p;
	j=q;
	
	while(i<j)
	{
		while(i<j && v[j]>=x) j--;
		v[i]=v[j];
		while(i<j && x>=v[i]) i++;
		v[j]=v[i];
	}
	v[j]=x;
	return i;
}

void quicksort2(int p, int q)
{
	int m;
	
	m=divide(p,q);
	
	if(p<m-1) quicksort2(p,m-1);
	if(m+1<q) quicksort2(m+1,q);
}

int main()
{
	intro();
	citire();
	
	quicksort2(0,n-1);
	afisare();

    printf("\n");
    return 0;
}
