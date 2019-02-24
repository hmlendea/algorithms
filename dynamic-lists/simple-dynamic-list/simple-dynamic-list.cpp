#include<stdio.h>
#include<string.h>
#include<alloc.h>

typedef struct nod{
	char cuv[21];
	struct nod *urm;
}NOD;

void Creare(NOD*& prim, NOD*& ultim)
{
	NOD *p=prim,*q;
	char s[21];
	int n;
	printf("n=");scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("cuv:");fflush(stdin);scanf("%s",&s);
		strupr(s);
		if(s[0]==s[strlen(s)-1])
		{
				q=(NOD*)malloc(sizeof(NOD));
				strcpy(q->cuv,s);
				q->urm=prim;
				prim=q;
		}
	}
}

void Parcurgere(NOD *prim, NOD* ultim)
{
	NOD *p=prim;
	while(p!=NULL)
	{	printf("%s ",p->cuv);
	p=p->urm;
	}
	printf("\n");
}

int main()
{
	NOD *prim,*ultim;
	prim=ultim=NULL;
	Creare(prim,ultim);
	Parcurgere(prim,ultim);
	return 0;
}