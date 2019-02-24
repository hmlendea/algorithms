#include<stdio.h>

int as, ev, k, st[100];
int n, l, m, p;
int t[100];

FILE *f, *g;

void citire()
{
	int i;
	f = fopen("atelier.in", "r");
	
	fscanf(f, "%d %d\n", &l, &n);
	
	for(i = 0; i<n; i++)
		fscanf(f, "%d ", &t[i]);
	
	fclose(f);
}

void afisare()
{
	g = fopen("atelier.out", "w");
	
	fprintf(g, "%d %d", m, p);
	
	fclose(g);
}

void init()
{
	st[k] = -1;
}

int succesor()
{
	if(st[k] < n)
	{
		st[k] += 1;
		return 1;
	}
	else return 0;
}

int valid()
{
	for(int i=1; i<k; i++)
	{
		if(st[i] == st[k]) return 0;
		else return 1;
	}
}

int solutie()
{
	return(k == n);
}

void tiparire()
{
	for(int i=1; i<=n; i++)
		printf("%d", st[i]);
	printf("\n");
}

void bt()
{
	k = 1;
	init();
	while(k > 0)
	{
		as = 1;
		ev = 0;
		while(as && !ev)
		{
			as = succesor();
			if(as) ev = valid();
		}
		
		if(as)
		{
			if(solutie()) tiparire();
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
	citire();
	afisare();
	return 0;
}