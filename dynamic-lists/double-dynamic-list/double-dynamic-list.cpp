#include<stdio.h>
#include<alloc.h>
typedef struct nod{
	int n;
	struct nod *urm,*ant;
}NOD;


void adaug_la_inceput(NOD*&prim,NOD*&ultim)
{
	NOD *p;
	p=(NOD*)malloc(sizeof(NOD));
	printf("nr=");scanf("%d",&p->n);
	p->ant=NULL;
	p->urm=prim;
	if(prim==NULL)
	prim=ultim=p;
	else
	{	prim->ant=p;
		prim=p;
	}
}
void adaug_la_coada(NOD*&prim,NOD*&ultim)
{
	NOD *p;
	p=(NOD*)malloc(sizeof(NOD));
	printf("nr=");scanf("%d",&p->n);
	p->urm=NULL;
	p->ant=ultim;
	if(ultim==NULL)
	prim=ultim=p;
	else
	{	ultim->urm=p;
		ultim=p;
	}
}
	
void parcurgere_crescator(NOD *prim, NOD *ultim)
{
	NOD *p;
	p=prim;
	while(p!=NULL)
	{
		printf("%d ",p->n);
		p=p->urm;
	}
}
void parcurgere_descrescator(NOD *prim, NOD *ultim)
{
	NOD *p;
	p=ultim;
	while(p!=NULL)
	{
		printf("%d ",p->n);
		p=p->ant;
	}
}

void adaug_zero_ineg(NOD *&prim, NOD *&ultim)
{
	NOD *p=prim,*q;
	while(p!=NULL)
	{
		if(p->n<0)
		{
			q=(NOD*)malloc(sizeof(NOD));
			q->n=0;
			if(p==prim)
			{
				p->ant=q;
				q->urm=p;
				q->ant=NULL;
				prim=q;
			}
			else
			{
				
				p->ant->urm=q;
				q->ant=p->ant;
				q->urm=p;
				p->ant=q;
			}
		}
		p=p->urm;
	}
}
				
			
				
			
			

int main()
{
	int op;
	NOD *prim,*ultim;
	prim=ultim=NULL;
	
	do{
		printf("1.Adaug element inainte \n");
		printf("2.Parcurgere lista \n");
		printf("3.Adaug element inapoi \n");
		printf("4.Parcurgere lista invers \n");
		printf("5.Adaug 0 inainte de negative \n");
		printf("6.Exit \n");
		printf("Alegeti opt:");scanf("%d",&op);
		switch(op)
		{
		case 1:{adaug_la_inceput(prim,ultim);break;}
		case 2:{parcurgere_crescator(prim,ultim);break;}
		case 3:{adaug_la_coada(prim,ultim);break;}
		case 4:{parcurgere_descrescator(prim,ultim);break;}
		case 5:{adaug_zero_ineg(prim,ultim);parcurgere_crescator(prim,ultim);break;}
		}
	}while(op!=6);
	
	return 0;
}

	