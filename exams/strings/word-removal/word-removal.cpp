#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f=fopen("string.txt", "r");
	char s[256], s2[256], cuv[32];
	char *p;
	int len;
	
	fscanf(f, "%d\n", &len);
	fgets(s, len+1, f);
	fclose(f);
	
	printf("Textul este: "); puts(s);
	printf("Introdu cuvantul pe care vrei sa il stergi: ");
	gets(cuv);
	
	s2[0]=NULL;
	p=strtok(s, " ");
	while(p!=NULL)
	{
		if(strcmp(p, cuv)!=0)
		{
			strcat(s2, p);
			strcat(s2, " ");
		}
		p=strtok(NULL, " ");
	}
	
	printf("\n\nRezultat: ");
	puts(s2);
	return 0;
}
