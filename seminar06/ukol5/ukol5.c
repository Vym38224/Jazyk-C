// Naprogramujte funkci, která jako argument bere pole čísel a vrátí (nové) pole jejich druhých mocnin(tedy prvek na indexu i vráceného pole bude mít hodnotu druhé mocniny prvku na indexu i vstupního pole)

#include <stdio.h>
#include <stdlib.h>

int *druha_mocnina(int *pole, int delka)
{
    int *vysledek = (int *)malloc(delka * sizeof(int));
    for (int i = 0; i < delka; i++)
    {
        vysledek[i] = pole[i] * pole[i];
    }
    return vysledek;
}

int main()
{
    int pole[] = {1, 2, 3, 4, 5};
    int delka = sizeof(pole) / sizeof(pole[0]);
    int *vysledek = druha_mocnina(pole, delka);
    for (int i = 0; i < delka; i++)
    {
        printf("%d ", vysledek[i]);
    }
    free(vysledek);
    return 0;
}
