#include <stdio.h>
#define n(x) (x + 1)
#define m(x) ((x) < 0 ? n(-x) : n(x))

int main()
{
    printf("Vysledek = %i\n", m(-3));

    return 0;
}
