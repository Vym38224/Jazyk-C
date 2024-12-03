#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int pole[10];

    for (int i = 0; i < 10; i++)
    {
        int k = i + 1;
        *(pole + i) = k * 7;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", *(pole + i));
    }
}
