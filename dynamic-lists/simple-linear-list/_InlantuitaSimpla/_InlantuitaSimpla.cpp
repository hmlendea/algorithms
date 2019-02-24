#include<stdio.h>
#include<alloc.h>

typedef struct nod{ int n;
					struct nod *urm;
				  }NOD;

void AdaugareDinFisier(NOD *&prim, NOD*&ultim)
{
	FILE *f=fopen("lista.in","r");
	printf("\nElementele au fost adaugate din fisierul 'lista.in'\n");
	int n,i;
	NOD *p;
	fscanf(f,"%d",&n);
	prim=(NOD*)malloc(sizeof(NOD));
	fscanf(f,"%d",&prim->n);
	prim->urm=NULL;
	ultim=prim;
	for(i=1;i<n;i++)
	{
		p=(NOD*)malloc(sizeof(NOD));
		fscanf(f,"%d",&p->n);
		p->urm=NULL;
		ultim->urm=p;
		ultim=p;
	}
	
	printf("\n\n");
}

void AdaugareInceput(NOD *&prim, NOD*&ultim)
{
	printf("\n----------\nCe element doriti sa adaugati?:\n");
	
	NOD *p;
	p=(NOD*)malloc(sizeof(NOD));
	p->urm=prim;
	printf("Valoarea ");
	scanf("%d", &p->n);
	if(prim==NULL)
		prim=ultim=p;
	else
		prim=p;
	printf("\n\n");
}

void AdaugareInainte(NOD *&prim, NOD *&ultim)
{
	printf("\n----------\nUnde doriti sa adaugati elementul?:\n");
	NOD *p, *q;
	int x;
	printf("Inainte de "); scanf("%d", &x);
	if(prim->n==x)
		AdaugareInceput(prim,ultim);
	else
		q=prim;
	while(q->urm->n!=x && q->urm!=NULL)
		q=q->urm;
	if(q->urm!=NULL)
	{
		p=(NOD*)malloc(sizeof(NOD));
		printf("Valoarea "); scanf("%d", &p->n);
		p->urm=q->urm;
		q->urm=p;
	}
	printf("\n\n");
}

void AdaugareDupa(NOD *&prim, NOD *&ultim)
{
	printf("\n----------\nUnde doriti sa adaugati elementul?:\n");
	NOD *p, *q;
	int x;
	printf("Dupa "); scanf("%d", &x);
	q=prim;
	while(q->n!=x && q!=NULL)
		q=q->urm;
	if(q!=NULL)
	{
		p=(NOD*)malloc(sizeof(NOD));
		printf("Valoarea "); scanf("%d", &p->n);
		p->urm=q->urm;
		q->urm=p;
		if(q==ultim)
			ultim=p;
	}
	printf("\n\n");
}

void AdaugareInainteImpare(NOD *&prim, NOD *&ultim)
{
	printf("\n----------\nUnde doriti sa adaugati elementul?:\n");
	NOD *p, *q;
	int x;
	printf("Valoarea "); scanf("%d", &p->n);
	if(prim->n%2!=0)
		AdaugareInceput(prim,ultim);
	else
		q=prim;
	while(q->urm->n!=x && q->urm!=NULL)
		q=q->urm;
	if(q->urm!=NULL)
	{
		p=(NOD*)malloc(sizeof(NOD));
		p->urm=q->urm;
		q->urm=p;
	}
	printf("\n\n");
}

void Parcurgere(NOD *&prim, NOD *&ultim)
{
	printf("\n----------\nElementele listei sunt:\n");
	NOD *p;
	p=prim;
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
	printf("\n\n");
}

int main()
{
	NOD *prim=NULL, *ultim=NULL;
	int op;
	do{
		printf("0. ---IESIRE---\n");
		printf("1. Adaugare din fisier\n");
		printf("2. Adaugare la inceput\n");
		printf("3. Adaugare inaintea unui anumit element\n");
		printf("4. Adaugare dupa un anumit alement\n");
		printf("5. Adaugare inaintea elementelor impare\n");
		printf("6. Parcurgere\n");
		
		printf("\nAlege: "); scanf("%d",&op);
		
		switch(op)
		{
			case 1: AdaugareDinFisier(prim, ultim); break;
			case 2: AdaugareInceput(prim, ultim); break;
			case 3: AdaugareInainte(prim, ultim); break;
			case 4: AdaugareDupa(prim, ultim); break;
			case 5: AdaugareInainteImpare(prim, ultim); break;
			case 6: Parcurgere(prim, ultim); break;
		}
	}while(op!=0);
	
	return 0;
}
