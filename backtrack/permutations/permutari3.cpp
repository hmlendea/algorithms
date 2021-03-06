#include<stdio.h>
int as,ev,st[20],k,n;

void init()
{
	st[k]=0;
}

int succesor()
{
	if(st[k]<n)
	{
		st[k]++;
		return 1;
	}
	else return 0;
}

int valid()
{
	if(k>1 && (st[k]-st[k-1]==1) || (st[k]-st[k-1]==-1)) return 0;
	for(int i=1;i<k;i++)
		if(st[k]==st[i]) return 0;
	return 1;
}

int solutie()
{
	return(k==n);
}

void tiparire()
{
	for(int i=1;i<=n;i++)
		printf("%d ",st[i]);
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