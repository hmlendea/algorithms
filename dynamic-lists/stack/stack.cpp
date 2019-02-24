#include<stdio.h>
#include<alloc.h>

typedef struct nod{ int n;
					struct nod *urm;
				  }NOD;

void adaugare(NOD *&varf)
{
	NOD *p;
	p=(NOD*)malloc(sizeof(NOD));
	if(p!=NULL)
	{
		printf("n="); scanf("%d",&p->n);
		p->urm=varf;
		varf=p;
	}
}

void parcurgere(NOD *&varf)
{
	NOD *p;
	p=varf;
	if(p==NULL)
		printf("Fara elemente.");
	else
	{
		while(p!=NULL)
		{
			printf("%d ",p->n);
			p=p->urm;
		}
	}
	printf("\n");
}
void stergere(NOD *&varf)
{
	NOD *p;
	p=varf;
	if(p!=NULL)
	{
		varf=varf->urm;
		free(p);
	}
}
void eliberare(NOD *&varf)
{
	NOD *p;
	p=varf;
	while(p!=NULL)
	{
		varf=varf->urm;
		free(p);
		p=varf;
	}
}
int main()
{
	NOD *varf=NULL;
	int op;
	do{
		printf("1. Adaugare\n");
		printf("2. Parcurgere\n");
		printf("3. Stergere\n");
		printf("4. Iesire\n");
		
		printf("\nAlege: "); scanf("%d",&op);
		
		switch(op)
		{
			case 1: adaugare(varf);break;
			case 2: parcurgere(varf);break;
			case 3: stergere(varf);break;
		}
	}while(op!=4);
	
	eliberare(varf);
	return 0;
}