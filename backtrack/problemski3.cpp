// Sa se genereze n paranteze a.i sa fie deschise si inchise corect

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
	int contor1=0, contor2=0;
	for(int i=1;i<=k;i++)
	{
		if(st[i]==1) contor1++;
		if(st[i]==2) contor2++;
	}
		if(contor2>contor1) return 0;
		if(contor2>n/2 || contor1>n/2) return 0;
		if(n%2!=0) return 0;
		else return 1;
}

int solutie()
{
	return(k==n);
}

void tiparire()
{
	for(int i=1;i<=n;i++)
	{
		if(st[i]==1) printf("(");
		if(st[i]==2) printf(")");
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