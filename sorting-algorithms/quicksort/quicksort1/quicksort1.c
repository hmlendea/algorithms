#include<stdio.h>

int v[873],n,i,j;

void intro()
{
	printf("=======================\n");
	printf("--- Quicksort I\n");
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
	printf("\n\n\nSirul sortat:");
	for(i=0;i<n;i++)
	{
		printf("%d ",v[i]);
	}
}

int quicksort1(int st, int dr)
{
	int x, aux;

	x=v[(st+dr)/2];
	i=st;
	j=dr;

	do
	{
		while(v[i]<x)
			i++;
		while(v[j]>x)
			j--;
		if(i<j)
		{
			aux=v[i];
			v[i]=v[j];
			v[j]=aux;
		}
		i++;
		j--;
	} while(i<=j);

	if(st < j)
		quicksort1(st,j);
	if(i < dr)
		quicksort1(i,dr);
}

int main()
{
	intro();
	citire();

	quicksort1(0,n-1);
	afisare();

	printf("\n");
	return 0;
}
