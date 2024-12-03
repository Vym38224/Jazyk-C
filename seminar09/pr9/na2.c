#define na2(x) ((x) * (x))
#define na2a(x) x *x
#include <stdio.h>

int main()
{
    int a = 1, b = 2;
    /* na2(f + g);   ((f+g)*(f+g)) */
    printf("Vysledek = %i \n", na2(a + b));
    /* na2a(f + g);       f+g*f+g */
    printf("Vysledek = %i \n", na2a(a + b));

    int i = 2;
    printf("Vysledek = %i \n", na2(i++));

    /*
        printf("Vysledek = %i \n", na2(a++));
    */
    return 0;
}
