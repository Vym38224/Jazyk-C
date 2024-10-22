#include <stdio.h>

int main()
{
    int pole1[] = {1, 2, 3, 9, 5, 6, 7, 8, 4, 10};
    int pole2[] = {1, 2, 9, 4, 5, 6, 7, 8, 3, 10};

    int i, j;
    int jeStejne = 1;
    int checked[10] = {0};

    for (i = 0; i < 10; i++)
    {
        int found = 0;
        for (j = 0; j < 10; j++)
        {
            if (pole1[i] == pole2[j] && !checked[j])
            {
                checked[j] = 1;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            jeStejne = 0;
            break;
        }
    }

    printf("Pole %s stejné hodnoty na různých indexech\n", jeStejne ? "obsahují" : "neobsahují");

    return 0;
}