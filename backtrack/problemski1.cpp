// numere cu n cifre cu proprietatea ca au cifrele strict pare

#include<stdio.h>

int as,ev,st[20],k,n;
int numar;

void init()
{
	st[k]=-2;
}

int succesor()
{
	if(st[k]<8)
	{
		st[k]+=2;
		return 1;
	}
	else return 0;
}

int valid()
{
	if(st[1]==0) return 0;
	return 1;
}

int solutie()
{
	return(k==n);
}

void tiparire()
{
	for(int i=1;i<=n;i++)
		numar=numar*10+st[i];
	printf("%d",numar); numar=0;
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