// program čte neexistující soubor

#include <stdio.h>

int main()
{
    FILE *f;
    float cislo;
    float soucet = 0;
    int pocet = 0;

    if ((f = fopen("../pr7/cisla.txt", "r")) == NULL)
    {
        printf("Nepodarilo se otevrit soubor.");
        return 1;
    }

    while (fscanf(f, "%f", &cislo) == 1)
    {
        soucet += cislo;
        pocet++;
    }

    printf("Prumer: %f\n", soucet / pocet);

    if (fclose(f) == EOF)
    {
        printf("Soubor se nepodarilo zavrit.");
        return 1;
    }
    return 0;
}
