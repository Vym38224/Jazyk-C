/*práce s čísly a a b */

#include <stdio.h>

int main()
{
    int a, b, i = 1;
    printf("Zadejte číslo a: ");
    scanf("%d", &a);
    printf("Zadejte číslo b: ");
    scanf("%d", &b);

    for (i; i <= a; i++)
    {
        b *= b;
        printf("%d\n", b);
    }

    return 0;
}