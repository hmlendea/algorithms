#include<stdio.h>
int as,ev,st[20],k,n,a[20][20];

void init()
{
	st[k]=1;
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
	int i;
	for(i=1;i<k;i++)
		if(st[k]==st[i])
			return 0;
	if(a[st[k-i]][st[k]]==0 && k>1)
		return 0;
	if(k==n & a[st[k]][st[i]]==0)
		return 0;
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
	st[1]=1;
	k=2;
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
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			printf("%d %d",i,j);
			scanf("5d",&a[i][j]);
			a[j][i]=a[i][j]=1;
		}
	}
	bt();
	return 0;
}