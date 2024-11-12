// program zpočítá počet znaku v souboru

#include <stdio.h>

int main()
{
    FILE *f;
    char znak;
    int pocet = 0;

    if ((f = fopen("../pr8/cisla.txt", "r")) == NULL)
    {
        printf("Nepodarilo se otevrit soubor.");
        return 1;
    }

    while (fscanf(f, "%c", &znak) == 1)
    {
        pocet++;
    }

    printf("Počet znaků: %i\n", pocet);

    if (fclose(f) == EOF)
    {
        printf("Soubor se nepodarilo zavrit.");
        return 1;
    }
    return 0;
}