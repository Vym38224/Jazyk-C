// program pro vstupní řetezec co obsahuje bin. číslo vrati toto císlo v desitkové soustavě

#include <stdio.h>

int main()
{

    char c;
    int cislo = 0;

    while ((c = getchar()) != '\n')
    {
        cislo = cislo * 2 + c - '0';
    }
    printf("%d\n", cislo);
    return 0;
}