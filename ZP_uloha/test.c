#include <stdio.h>
#include "obrazek.c"

int main()
{
    obrazek obr1, obr2, obr3, obr4, obr5, obr6;
    obr1 = cerny(3, 3);
    nastav_prvek(obr1, 0, 0, 0);
    nastav_prvek(obr1, 0, 1, 1);
    nastav_prvek(obr1, 0, 2, 2);
    nastav_prvek(obr1, 1, 0, 1);
    nastav_prvek(obr1, 1, 1, 2);
    nastav_prvek(obr1, 1, 2, 3);
    nastav_prvek(obr1, 2, 0, 2);
    nastav_prvek(obr1, 2, 1, 3);
    nastav_prvek(obr1, 2, 2, 4);
    printf(" Obrazek obr1 : \n");
    zobraz(obr1);
    printf("\n\n");
    obr2 = otoc90(obr1);
    printf("Otoceny obrazek obr1 : \n");
    zobraz(obr2);
    printf("\n\n");
    printf("Minimalni intenzita obr2 : %i \n", min(obr2));
    printf("Maximalni intenzita obr2 : %i \n\n", max(obr2));
    obr3 = morfing(obr1, obr2);
    printf("Morfing obrazku obr1 + obr2 : \n");
    switch (chyba)
    {
    case CHYBA_TYPU:
        printf("Morfing nelze provest s ruzne velkymi obrazky.");
        break;
    case CHYBA_ALOKACE:
        printf("Nastala chyba alokace pameti.");
        break;
    case BEZ_CHYBY:
        zobraz(obr3);
        break;
    }
    printf("\n\n");
    obr4 = cerny(10, 5);
    obr5 = morfing(obr1, obr5);
    printf("Morfing obrazku obr1 + obr5 : \n");
    switch (chyba)
    {
    case CHYBA_TYPU:
        printf("Morfing nelze provest s ruzne velkymi obrazky.");
        break;
    case CHYBA_ALOKACE:
        printf("Nastala chyba alokace pameti.");
        break;
    case BEZ_CHYBY:
        zobraz(obr5);
        break;
    }
    printf("\n\n");
    obr5 = jasova_operace(obr1, NEGATIV);
    printf("Negativ obrazku obr1 : \n");
    zobraz(obr5);
    printf("\n\n");
    obr6 = jasova_operace(obr1, ZMENA_KONTRASTU, 0.5, 1);
    printf("Zmena kontrastu obrazku obr1 : \n");
    zobraz(obr6);
    printf("\n\n");

    // Vytvoření testovacího souboru
    const char *test_soubor = "test_input.txt";
    FILE *f = fopen(test_soubor, "w");
    if (f == NULL)
    {
        perror("Nelze vytvořit testovací soubor");
        return 1;
    }

    fprintf(f, "1 2 3\n4 5 6\n7 8 9\n");
    fclose(f);

    // Načtení obrázku ze souboru
    obrazek obr = nacti_ze_souboru(test_soubor);
    if (obr.data == NULL)
    {
        printf("Chyba při načítání obrázku\n");
        return 1;
    }

    // Uložení obrázku do nového souboru
    const char *output_soubor = "test_output.txt";
    uloz_do_souboru(obr, output_soubor);

    return 0;
}
