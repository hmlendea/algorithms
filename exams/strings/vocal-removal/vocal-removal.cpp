#include<stdio.h>
#include<string.h>

int main()
{
	char s[256];
	int i, nr=0;
	
	printf("Introdu un text de maxim 256 de caractere:\n");
	gets(s);
	
	for(i=0; i<strlen(s); i++)
		if(strchr("aeiouAEIOU", s[i]))
		{
			strcpy(s+i, s+i+1);
			nr+=1;
		}
		
	printf("\n\nAm gasit si am eliminat %d vocale!\n", nr);
	puts(s);
	
	return 0;
}
