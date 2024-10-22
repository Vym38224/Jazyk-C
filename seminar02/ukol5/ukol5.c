/*Načtěte ze vstupu trojciferné číslo a poté vypište jeho první a poslední číslici*/

#include <stdio.h>

int main()
{
    int cislo;
    printf("Zadejte trojciferné číslo: ");
    scanf("%d", &cislo);

    int prvni = cislo / 100;
    int posledni = cislo % 10;

    printf("První číslice je: %d\n", prvni);
    printf("Poslední číslice je: %d\n", posledni);

    return 0;
}