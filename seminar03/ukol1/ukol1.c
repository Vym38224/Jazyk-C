#include <stdio.h>
/*absolutní hodnota čísla*/
int main()
{
    int a, x;
    printf("Zadejte číslo: ");
    scanf("%d", &a);
    x = (a < 0) ? -a : a;
    printf("Absolutní hodnota čísla %d je %d\n", a, x);

    return 0;
}
