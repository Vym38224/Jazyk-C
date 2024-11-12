#include <stdio.h>

void zmen_cislo_na_5(int *cislo)
{
    *cislo = 5;
}

int main()
{
    int cislo = 4;
    zmen_cislo_na_5(&cislo);
    printf("%d ", cislo);
    return 0;
}
