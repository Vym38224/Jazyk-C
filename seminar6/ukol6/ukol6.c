// Vytvořte strukturu matice, která bude obsahovat její rozměry int m a int n a položku data(dvourozměrné pole velikosti m × n).Vytvořte funkci, která jako argument bude
// brát dva int(m a n). Funkce bude vracet nulovou matici velikosti m × n(všechny prvky matice jsou rovny 0)

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int m;
    int n;
    int **data;
} Matice;

Matice nulova_matice(int m, int n)
{
    Matice matice;
    matice.m = m;
    matice.n = n;
    matice.data = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        matice.data[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            matice.data[i][j] = 0;
        }
    }
    return matice;
}

int main()
{
    Matice matice = nulova_matice(3, 3);
    for (int i = 0; i < matice.m; i++)
    {
        for (int j = 0; j < matice.n; j++)
        {
            printf("%d ", matice.data[i][j]);
        }
        printf("\n");
    }
    free(matice.data);
    return 0;
}