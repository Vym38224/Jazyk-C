#include <stdio.h>

int main()
{
    int i;

    for (i = 0; i < 10; i++)
        ; // středník na konci cyklu
    {
        printf("%i ", i);
    }
    return 0;
}
