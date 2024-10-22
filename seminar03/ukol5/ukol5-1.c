/*práce s čísly a a b */

#include <stdio.h>

int main()
{
    int a, b, p, i = 1;
    printf("Zadejte číslo a: ");
    scanf("%d", &a);
    printf("Zadejte číslo b: ");
    scanf("%d", &b);

    p = b;
    for (i; i <= a; i++)
    {
        b = i * p;
        printf("%d\n", b);
    }

    return 0;
}