// uloha: načíst čísla ze souboru do dvourozměrného pole a vypsat je

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("cisla.txt", "r");
    if (f == NULL)
    {
        printf("Soubor cisla.txt se nepodarilo otevrit\n");
        return 1;
    }

    int rows = 2; // Počet řádků
    int cols = 3; // Počet sloupců

    // Dynamická alokace paměti pro dvourozměrné pole
    float **cisla = (float **)malloc(rows * sizeof(float *));
    for (int i = 0; i < rows; i++)
    {
        cisla[i] = (float *)malloc(cols * sizeof(float));
    }

    // Načtení čísel ze souboru do pole
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (fscanf(f, "%f", &cisla[i][j]) != 1)
            {
                printf("Chyba při čtení souboru.\n");
                fclose(f);
                return 1;
            }
        }
    }

    if (fclose(f) == EOF)
    {
        printf("Soubor cisla.txt se nepodarilo zavrit.\n");
        return 1;
    }

    // Výpis čísel z pole
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%.1f ", cisla[i][j]); // Použití %.1f pro výpis čísel s jedním desetinným místem
        }
        printf("\n");
    }

    // Uvolnění paměti
    for (int i = 0; i < rows; i++)
    {
        free(cisla[i]);
    }
    free(cisla);

    return 0;
}