#include <stdio.h>

int main()
{
    int i;

    for (i = 0, i < 10, i++)
    { // chybí středníky ve for
        printf("%i ", i);
    }
    return 0;
}
