#include <stdio.h>

int get_pascal(int row, int col)
{
    if (col == 0 || col == row)
        return 1;
    else
        return get_pascal(row - 1, col - 1) + get_pascal(row - 1, col);
}

void print_pascal(int dim)
{
    int k, i;

    for (i = 0; i < dim; i++)
    {
        for (k = 0; k < dim - i - 1; k++)
            printf(" ");

        for (k = 0; k <= i; k++)
            printf("%d ", get_pascal(i, k));

        printf("\n");
    }
}

int main(void)
{
    int n;
    printf("Numarul de linii: ");
    scanf("%d", &n);
    print_pascal(n);

    printf("\n");
    return 0;
}

