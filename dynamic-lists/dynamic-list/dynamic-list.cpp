#include<alloc.h>
#include<stdio.h>
FILE *f=fopen("listadinamica.in","r");
typedef struct nod{ int n;
					nod *urm;
					}NOD;
void citire(NOD *&prim, NOD *&ultim)
{
	int n,i;
	NOD *p;
	fscanf(f,"%d",&n);
	
	prim=(NOD*)malloc(sizeof(NOD));
	fscanf(f,"%d",&prim->n);
	prim->urm=NULL;
	ultim=prim;
	for(i=0;i<n-1;i++)
	{
	p=(NOD*)malloc(sizeof(NOD));
	fscanf(f,"%d",&p->n);
	p->urm=NULL;
	ultim->urm=p;
	ultim=p;
	}
}
int nprim(int a)
{
	int j=0;
	for(int i=2;i<=a/2;i++)
		if(a%i==0)
			j++;
	if(j==0 && (a!=0 && a!=1))
		return 1;
	else return 0;
}
void stergeprim(NOD *&prim, NOD *&ultim)
{
	NOD *p=prim,*q;
	while(1)
	if(nprim(prim->n) && prim->urm!=NULL)
		{	
			prim=prim->urm;
			free(p);
			p=prim;
		}
	else
		break;
	p=prim;
	while(p!=ultim)
	{
		q=p->urm;
		if(nprim(q->n))
		{
			if(q==ultim)
				ultim=p;
			p->urm=q->urm;
			free(q);
		}
		else
			p=p->urm;
	}
}
void parcurgere(NOD *prim, NOD* ultim)
{
	NOD *p=prim;
	while(p!=NULL)
	{	printf("%d ",p->n);
	p=p->urm;
	}
	printf("\n");
}

void inszero(NOD*&prim, NOD*&ultim)
{
	NOD *p=prim,*q;
	while(p!=NULL)
	{	if(p->n%2==1)
		{q=(NOD*)malloc(sizeof(NOD));
		q->n=0;
		q->urm=p->urm;
		p->urm=q;}
		p=p->urm;
	}
	p=prim;
	while(p!=NULL)
	{	if(p->urm==NULL)
			ultim=p;
		p=p->urm;
	}
		
}
	
	
int main()
{
	NOD *prim,*ultim;

	citire(prim,ultim);
	parcurgere(prim, ultim);
	
	//inszero(prim,ultim);
	parcurgere(prim, ultim);
	
	stergeprim(prim, ultim);
	parcurgere(prim, ultim);
	return 0;
}
		