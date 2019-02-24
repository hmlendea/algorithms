// Sa se genereze toate codurile morse de lungime n reprezentate prin "_" sau ".", astfel incat
// intr-o secventa sa nu existe doua puncte alaturate

#include<stdio.h>

int as,ev,st[20],k,n;

void init()
{
	st[k]=0;
}

int succesor()
{
	if(st[k]<2)
	{
		st[k]++;
		return 1;
	}
	else return 0;
}

int valid()
{
	for(int i=1;i<k;i++)
	{
		if(st[i]==1 && st[i+1]==1) return 0;
	}
	return 1;
}

int solutie()
{
	return(k==n);
}

void tiparire()
{
	for(int i=1;i<=n;i++)
	{
		if(st[i]==1) printf(".");
		if(st[i]==2) printf("_");
	}
	printf("\n");
}

void bt()
{
	k=1;
	init();
	while(k>0)
	{
		as=1; ev=0;
		while(as && !ev)
		{
			as=succesor();
			if(as) ev=valid();
		}
		if(as)
		{
			if(solutie())
				tiparire();
			else
			{
				k++;
				init();
			}
		}
		else k--;
	}
}
int main()
{
	printf("n= "); scanf("%d",&n);
	bt();
	return 0;
}