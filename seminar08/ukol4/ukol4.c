// uloží čísla do binárního souboru a textového souboru

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f, *f1;
    int cislo;
    int pocet = 0;
    char vstup[100];

    if ((f = fopen("cislabinto.txt", "wt")) == NULL)
    {
        printf("Nepodarilo se otevrit soubor cisla.bin.\n");
        return 1;
    }

    if ((f1 = fopen("cisla.txt", "wt")) == NULL)
    {
        printf("Nepodarilo se otevrit soubor cisla.txt.\n");
        return 1;
    }

    printf("Zadejte cisla (nebo 'q' pro ukonceni):\n");
    while (1)
    {
        scanf("%s", vstup);
        if (strcmp(vstup, "q") == 0)
        {
            break;
        }
        if (sscanf(vstup, "%i", &cislo) == 1)
        {
            // do binarniho souboru
            fwrite(&cislo, sizeof(int), 1, f);
            // do textoveho souboru
            fprintf(f1, "%i", cislo);

            pocet++;
        }
        else
        {
            printf("Neplatny vstup, zkuste to znovu.\n");
        }
    }
    printf("Zapsano %d cisel.\n", pocet);

    if (fclose(f) == EOF)
    {
        printf("Soubor cisla.bin se nepodarilo zavrit.\n");
        return 1;
    }

    if (fclose(f1) == EOF)
    {
        printf("Soubor cisla.txt se nepodarilo zavrit.\n");
        return 1;
    }

    // otevření obou souborů pro čtení a zjištění jejich velikostí
    if ((f = fopen("cisla.bin", "rb")) == NULL)
    {
        printf("Nepodarilo se otevrit soubor cisla.bin.\n");
        return 1;
    }

    if ((f1 = fopen("cisla.txt", "rt")) == NULL)
    {
        printf("Nepodarilo se otevrit soubor cisla.txt.\n");
        return 1;
    }

    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    fseek(f1, 0, SEEK_END);
    int size1 = ftell(f1);

    printf("Velikost binarniho souboru: %d\n", size);
    printf("Velikost textoveho souboru: %d\n", size1);

    if (fclose(f) == EOF)
    {
        printf("Soubor cisla.bin se nepodarilo zavrit.\n");
        return 1;
    }

    if (fclose(f1) == EOF)
    {
        printf("Soubor cisla.txt se nepodarilo zavrit.\n");
        return 1;
    }

    return 0;
}