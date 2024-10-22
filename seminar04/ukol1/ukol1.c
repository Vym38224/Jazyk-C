#include <stdio.h>

int main()
{

    int pole1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int pole2[] = {1, 2, 3, 4, 5, 6, 7, 8, 3, 10};

    int i;
    int jeStejne = 1;

    for (i = 0; i < 10; i++)
    {
        if (pole1[i] != pole2[i])
        {
            jeStejne = 0;
            break;
        }
    }
    printf("Pole jsou %s\n", jeStejne ? "stejné" : "rozdílné");

    return 0;
}
