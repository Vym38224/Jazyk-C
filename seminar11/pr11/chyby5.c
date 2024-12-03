#include <stdio.h>

int main()
{
    int b;
    // chybí inicializace proměnné b
    while (b > 0)
    {
        printf("*");
        b--;
    }
    return 0;
}
