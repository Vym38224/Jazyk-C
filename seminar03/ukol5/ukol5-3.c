/*práce s čísly a a b */

#include <stdio.h>
int main()
{
    int a, i = 1;
    printf("Zadejte číslo a: ");
    scanf("%d", &a);

    while (a / 10 != 0)
    {
        a /= 10;
        i++;
    }
    printf("Číslo a má %d číslic.\n", i);

    return 0;
}