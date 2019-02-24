#include <stdio.h>
#include <stdlib.h>

// Se citeste de la tastatura o matrice patratica a cu n linii si n coloane continand numere naturale (3<=n<=50, 1<=a[i][j]<=20000)
// Scrieti un program care determina si apoi tipareste sirul X, continand in ordine descrescatoare, numerele "superprime" distincte,
// care apar in triunghiul stang sau cel drept al matricei a. Sirul X se va construi direct ordonat, fara a fae ordonarea ulterioara.
// In cazul in care sirul X este vid, se va tipari mesajul "Sirul este vid"
//
// Un numar se numeste "superprim" daca toate prefixele sale sunt numere prime
// Ex: 239 este "superprim" deoarece 2, 23, 239 sunt prime
// Ex: 241 nu este "superprim" deoarece 24 nu este prim
//
// Se vor scrie subprograme pentru:
// a) Citirea unei matrici patratice
// b) Tiparirea unui sir
// c) Verificarea daca un numar este prim
// d) Verificarea daca un numar este "superprim"
// e) Inserarea unei valori intr-un sir ordonat descrescator
// f) Construirea sirului X
//
// Exemplu 1:
// n=4
//  16|241| 15| 8
// 239| 3 | 2 | 79
// 241|100| 5 |239
// X={239, 79}
//
// Triunghiul stang al matricei este cel marcat cu 2, iar triunghiul drept este cel marcat cu 3 in figura de mai jos:
// \ 1 /
//  \ /
// 2 X 3
//  / \
// / 4 \
//
// Pentru n=4, triunghiul stang al matricei a contine elementele a[2][1] si a[3][1],
// iar triunghiul drept contine elementele a[2][4] si a[3][4].
// Nu se iau in considerare elementele de pe cele doua diagonale

int a[51][51], x[52];
int n, m;

void citireMatrice()
{
    int i, j;

    printf("n=");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            printf("a[%d][%d]=", i, j);
            scanf("%d", &a[i][j]);
        }
}

void afisareMatrice()
{
    int i, j;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void afisareSir()
{
    int i;

    printf("X={");
    for(i=0; i<m; i++)
        if(i<m-1)
            printf("%d, ", x[i]);
        else
            printf("%d", x[i]);

    printf("}");
}

int prim(int nr)
{
    int i;

    for(i=2; i<nr; i++)
        if(nr%i==0)
            return 0;

    return 1;
}

int superprim(int nr)
{
    while(nr>0)
    {
        if(prim(nr)==0)
            return 0;
        nr/=10;
    }

    return 1;
}

void inserareSir(int nr)
{
    int i, pos=-1;

//    if(m==0)
//    {
//        x[0]=nr;
//        m=1;
//        return;
//    }

    for(i=0; i<m; i++)
        if(nr==x[i])
            return;
        else if(nr>x[i])
        {
            pos=i;
            break;
        }

    if(pos==-1)
    {
        x[m]=nr;
        m+=1;
        return;
    }

    for(i=m; i>pos; i--)
        x[i] = x[i-1];

    x[pos] = nr;
    m+=1;
}

void construireSir()
{
    // DP: i==j
    // DS: i+j==n+1)
    // T1: i<j && i+j<=n
    // T2: i<j && i+j >n
    // T3: i>j && i+j >n
    // T4: i>j && i+j<=n

    int i, j;

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(i!=j && i+j!= n+1)
                if((i<j && i+j>n) || (i>j && i+j<=n)) // Triunghiul stang sau drept
                    if(superprim(a[i][j]))
                        inserareSir(a[i][j]);
}

int main()
{
    citireMatrice();
    construireSir();
    afisareSir();

    return 0;
}
