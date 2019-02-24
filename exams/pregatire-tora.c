#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse(char *str)
{
    int len = strlen(str);
    int i;
    char aux;
    for (i = 0; i < len / 2; i++)
    {
       aux = str[i];
       str[i] = str[len - 1 - i];
       str[len - 1 - i] = aux;
    }
}

void problema1()
{
    char s[256];
    char *p;

    printf("Problema 1.\nPropozitie: ");
    setbuf(stdin, NULL);
    gets(s);
    reverse(s);

    printf("Rezultat  : ");
    p = strtok(s, " ");
    while(p != NULL)
    {
        reverse(p);
        printf("%s ", p);
        p = strtok(NULL, " ");
    }
    printf("\n");
}
void problema2()
{
    int v[200];
    int n, ok;
    int i, j;

    printf("Problema 2.\n");

    printf("n=");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("v[%d]=", i);
        scanf("%d", &v[i]);
    }

    for(i = 0; i < n; i++)
    {
        ok = 1;
        for(j = i; j < n; j++)
            if (v[i] == v[j])
            {
                ok = 0;
                break;
            }

        if(ok)
        {
            printf("%d", i);
            break;
        }
    }
    printf("%d", i);
}

void problema3()
{
    printf("Problema 3.\n");

    char s[256];
    char s2[256];
    int i, j;
    int ok;

    setbuf(stdin, NULL);
    printf("Propozitie: ");
    gets(s);

    i = j = 0;
    for(i = 0; i < (int)strlen(s); i++)
    {
        if(isalnum(s[i]))
        {
            s2[j] = tolower(s[i]);
            j += 1;
        }
    }

    ok = 1;
    for (i = 0; i < (int)strlen(s2) / 2; i++)
        if (s2[i] != s2[j  - 1 - i])
        {
            ok = 0;
            break;
        }

    printf("%d", ok);
}

void problema11()
{
    printf("Problema 11.\n");
    int n, d, s;
    int ok;

    for (n = 1; ok == 0; n += 2)
    {
        s = 0;
        for (d = 1; d < n * 0.5 + 1; d++)
            if (n % d == 0)
                s += d;
        if(s > n)
            ok = 1;
    }

    printf("Cel mai mic numar natural pentru care suma divizorilor este mai mare decat acesta: %d", n);
}

int main(void)
{
    int prb;
    int ok = 0;

    while(!ok)
    {
        printf("Alege o problema (1, 2, 3, 11): ");
        scanf("%d", &prb);

        switch(prb)
        {
        case 1:
            problema1();
            ok = 1;
            break;
        case 2:
            problema2();
            ok = 1;
            break;
        case 3:
            problema3();
            ok = 1;
            break;
        case 11:
            problema11();
            ok = 1;
            break;
        default:
            printf("Problema invalida!\n");
            break;
        }
    }

    printf("\n");
    return 0;
}
