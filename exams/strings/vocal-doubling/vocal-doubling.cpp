#include<stdio.h>
#include<string.h>

int main()
{
	char s[256], s2[256];
	int len;
	
	printf("Introdu un text de maxim 256 de caractere:\n");
	gets(s);
	len=strlen(s);
	
	for(int i=0; i<strlen(s); i++)
		if(strchr("aeiouAEIOU", s[i]))
		{
			for(int j=len; j>i; j--)
				s[j]=s[j-1];
			
			len+=1;
			s[len]='\0';
			
			i+=1;
		}
	
	printf("Rezultat: ");
	puts(s);
	
	return 0;
}
