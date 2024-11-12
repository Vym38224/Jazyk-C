#include <stdio.h>
#include <stdlib.h>

int *druha_mocnina(int pole[], int velikost)
{
    int *pole2 = malloc(velikost * sizeof(int));
    int i;

    for (i = 0; i < velikost; i++)
    {
        pole2[i] = pole[i] * pole[i];
    }

    return pole2;
}

int main(int argc, char *argv[])
{
    int pole[5] = {1, 2, 3, 4, 5};
    int *pole2 = druha_mocnina(pole, 5);
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("%d ", pole2[i]);
    }

    free(pole2);
    return 0;
}
