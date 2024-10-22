#include <stdio.h>
#include <stdlib.h>

// Napište program, který pro celočíselné argumenty m a n(zadané od uživatele) alokuje dvourozměrné pole o velikosti m × n.
// Prvky pole budou reprezentovat násobky.Tedy prvek pole na indexu i, j bude roven i · j.Toto pole vypište.

int main()
{
    int m, n;
    printf("Enter m: ");
    scanf("%d", &m);
    printf("Enter n: ");
    scanf("%d", &n);

    int **array = (int **)malloc(m * sizeof(int *));
    if (array == NULL)
    {
        printf("Memory allocation failed for array.\n");
        return 1;
    }

    for (int i = 0; i < m; i++)
    {
        array[i] = (int *)malloc(n * sizeof(int));
        if (array[i] == NULL)
        {
            printf("Memory allocation failed for array[%d].\n", i);
            // Free
            for (int k = 0; k < i; k++)
            {
                free(array[k]);
            }
            free(array);
            return 1;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[i][j] = i * j;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // Free
    for (int i = 0; i < m; i++)
    {
        free(array[i]);
    }
    free(array);

    return 0;
}