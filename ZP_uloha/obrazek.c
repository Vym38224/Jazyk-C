#include "obrazek.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

// Globální proměnná pro uchování stavu chyby
int chyba = BEZ_CHYBY;

// Funkce pro inicializaci obrázku. Vytvoři obrazek o velikosti h × w včetně alokace paměti pro data
obrazek inicializace(int h, int w)
{
    obrazek obr;
    obr.h = h;
    obr.w = w;
    obr.data = (short **)malloc(h * sizeof(short *));
    if (obr.data == NULL)
    {
        chyba = CHYBA_ALOKACE;
        obr.h = 0;
        obr.w = 0;
        return obr;
    }
    for (int i = 0; i < h; i++)
    {
        obr.data[i] = (short *)malloc(w * sizeof(short));
        if (obr.data[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(obr.data[j]);
            }
            free(obr.data);
            chyba = CHYBA_ALOKACE;
            obr.h = 0;
            obr.w = 0;
            return obr;
        }
    }
    chyba = BEZ_CHYBY;
    return obr;
}

// Funkce pro vytvoření černého obrázku
obrazek cerny(int h, int w)
{
    obrazek obr_cerny = inicializace(h, w);
    if (obr_cerny.data == NULL)
    {
        // Inicializace selhala, vracíme prázdný obrázek
        return obr_cerny;
    }
    for (int i = 0; i < vyska(obr_cerny); i++)
    {
        for (int j = 0; j < sirka(obr_cerny); j++)
        {
            nastav_prvek(obr_cerny, i, j, 0);
        }
    }
    chyba = BEZ_CHYBY;
    return obr_cerny;
}

// Funkce pro odstranění obrázku
void odstran(obrazek obr)
{
    for (int i = 0; i < vyska(obr); i++)
    {
        free(obr.data[i]);
    }
    free(obr.data);
    chyba = BEZ_CHYBY;
}

// Funkce pro zobrazení obrázku
void zobraz(obrazek obr)
{
    for (int i = 0; i < vyska(obr); i++)
    {
        for (int j = 0; j < sirka(obr); j++)
        {
            switch (prvek(obr, i, j))
            {
            case 0:
                printf(" ");
                break;
            case 1:
                printf(".");
                break;
            case 2:
                printf(":");
                break;
            case 3:
                printf("+");
                break;
            case 4:
                printf("#");
                break;
            default:
                printf("?!?");
                break;
            }
        }
        printf("\n");
    }
    chyba = BEZ_CHYBY;
}

// Funkce pro otočení obrázku o 90 stupňů doleva
obrazek otoc90(obrazek obr)
{
    obrazek obr_otoc90 = inicializace(sirka(obr), vyska(obr));
    if (obr_otoc90.data == NULL)
    {
        // Inicializace selhala, vracíme prázdný obrázek
        chyba = CHYBA_ALOKACE;
        return obr_otoc90;
    }
    for (int i = 0; i < vyska(obr); i++)
    {
        for (int j = 0; j < sirka(obr); j++)
        {
            nastav_prvek(obr_otoc90, sirka(obr) - 1 - j, i, prvek(obr, i, j));
        }
    }
    chyba = BEZ_CHYBY;
    return obr_otoc90;
}

// Funkce pro morfing dvou obrázků
obrazek morfing(obrazek obr1, obrazek obr2)
{
    if (obr1.h != obr2.h || obr1.w != obr2.w)
    {
        chyba = CHYBA_TYPU;
        obrazek prazdny;
        prazdny.h = 0;
        prazdny.w = 0;
        prazdny.data = NULL;
        return prazdny;
    }

    obrazek vysledek = inicializace(obr1.h, obr1.w);
    if (vysledek.data == NULL)
    {
        // Inicializace selhala, vracíme prázdný obrázek
        chyba = CHYBA_ALOKACE;
        return vysledek;
    }

    for (int i = 0; i < vyska(vysledek); i++)
    {
        for (int j = 0; j < sirka(vysledek); j++)
        {
            short hodnota1 = prvek(obr1, i, j);
            short hodnota2 = prvek(obr2, i, j);
            short nova_hodnota = (short)((hodnota1 + hodnota2) / 2.0 + 0.5);
            nastav_prvek(vysledek, i, j, nova_hodnota);
        }
    }

    chyba = BEZ_CHYBY;
    return vysledek;
}

// Funkce pro získání minimální hodnoty pixelu
short min(obrazek obr)
{
    short min_val = prvek(obr, 0, 0);
    for (int i = 0; i < vyska(obr); i++)
    {
        for (int j = 0; j < sirka(obr); j++)
        {
            if (prvek(obr, i, j) < min_val)
            {
                min_val = prvek(obr, i, j);
            }
        }
    }
    chyba = BEZ_CHYBY;
    return min_val;
}

// Funkce pro získání maximální hodnoty pixelu
short max(obrazek obr)
{
    short max_val = prvek(obr, 0, 0);
    for (int i = 0; i < vyska(obr); i++)
    {
        for (int j = 0; j < sirka(obr); j++)
        {
            if (prvek(obr, i, j) > max_val)
            {
                max_val = prvek(obr, i, j);
            }
        }
    }
    chyba = BEZ_CHYBY;
    return max_val;
}

// Funkce pro jasovou operaci
obrazek jasova_operace(obrazek obr, operace o, ...)
{
    va_list args;      // Proměnná pro argumenty
    va_start(args, o); // Inicializace proměnné pro argumenty

    obrazek obr2 = inicializace(vyska(obr), sirka(obr));
    if (obr2.data == NULL)
    {
        // Inicializace selhala, vracíme prázdný obrázek
        chyba = CHYBA_ALOKACE;
        va_end(args);
        return obr2;
    }

    switch (o)
    {
    case NEGATIV:
        for (int i = 0; i < vyska(obr); i++)
        {
            for (int j = 0; j < sirka(obr); j++)
            {
                nastav_prvek(obr2, i, j, 4 - prvek(obr, i, j));
            }
        }
        break;
    case ZMENA_JASU:
    {
        int hodnota = va_arg(args, int); // Hodnota jasu
        for (int i = 0; i < vyska(obr); i++)
        {
            for (int j = 0; j < sirka(obr); j++)
            {
                short nova_hodnota = prvek(obr, i, j) + hodnota;
                if (nova_hodnota < 0)
                {
                    nova_hodnota = 0;
                }
                if (nova_hodnota > 4)
                {
                    nova_hodnota = 4;
                }
                nastav_prvek(obr2, i, j, nova_hodnota);
            }
        }
        break;
    }
    case ZMENA_KONTRASTU:
    {
        double k1 = va_arg(args, double); // mění kontrast
        int k2 = va_arg(args, int);       // mění jas
        for (int i = 0; i < vyska(obr); i++)
        {
            for (int j = 0; j < sirka(obr); j++)
            {
                int nova_hodnota = (int)(k1 * prvek(obr, i, j) + k2 + 0.5); // Zaokrouhlení (int) + 0.5
                if (nova_hodnota < 0)
                {
                    nova_hodnota = 0;
                }
                if (nova_hodnota > 4)
                {
                    nova_hodnota = 4;
                }
                nastav_prvek(obr2, i, j, nova_hodnota);
            }
        }
        break;
    }
    default:
        chyba = CHYBA_TYPU;
        va_end(args);
        return inicializace(0, 0);
    }

    va_end(args);
    chyba = BEZ_CHYBY;
    return obr2;
}

// Funkce pro načtení obrázku ze souboru
obrazek nacti_ze_souboru(const char *soubor)
{
    FILE *f = fopen(soubor, "r");
    if (f == NULL)
    {
        chyba = CHYBA_OTEVRENI;
        obrazek prazdny;
        prazdny.h = 0;
        prazdny.w = 0;
        prazdny.data = NULL;
        return prazdny;
    }

    int h = 0, w = 0;
    char line[1024];

    // Načítání řádek po řádku pro zjištění výšky a následně i šířky
    while (fgets(line, sizeof(line), f))
    {
        if (h == 0)
        {
            // Zjištění šířky z prvního řádku
            char *p = line;
            while (*p != "\0")
            {
                // Přeskočíme mezery
                while (*p == " ")
                {
                    p++;
                }
                if (*p != "\0")
                {
                    w++;
                    // Přeskočíme číslo
                    while (*p != " " && *p != "\0")
                    {
                        p++;
                    }
                }
            }
        }
        h++;
    }

    // Inicializace obrázku
    obrazek obr = inicializace(h, w);
    if (obr.data == NULL)
    {
        // Inicializace selhala, zavřeme soubor a vrátíme prázdný obrázek
        fclose(f);
        chyba = CHYBA_ALOKACE;
        return obr;
    }

    // Přesuneme se zpět na začátek souboru
    rewind(f);

    // Načítání hodnot pixelů do obrázku
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            short hodnota;
            fscanf(f, "%hi", &hodnota);
            nastav_prvek(obr, i, j, hodnota);
        }
    }

    fclose(f);
    chyba = BEZ_CHYBY;
    return obr;
}

// Funkce pro uložení obrázku do souboru
void uloz_do_souboru(obrazek obr, const char *soubor)
{
    FILE *f = fopen(soubor, "w");
    if (f == NULL)
    {
        chyba = CHYBA_OTEVRENI;
        return;
    }

    for (int i = 0; i < vyska(obr); i++)
    {
        for (int j = 0; j < sirka(obr); j++)
        {
            fprintf(f, "%hi", prvek(obr, i, j));
            if (j < sirka(obr) - 1)
            {
                fprintf(f, " ");
            }
        }
        fprintf(f, "\n");
    }

    fclose(f);
    chyba = BEZ_CHYBY;
}

// Pomocné funkce
int vyska(obrazek obr)
{
    chyba = BEZ_CHYBY;
    return obr.h;
}

int sirka(obrazek obr)
{
    chyba = BEZ_CHYBY;
    return obr.w;
}

short prvek(obrazek obr, int i, int j) // Funkce vrací hodnotu pixelu na pozici i, j
{
    if (i < 0 || i >= obr.h || j < 0 || j >= obr.w)
    {
        chyba = CHYBA_TYPU;
        return -1;
    }
    chyba = BEZ_CHYBY;
    return obr.data[i][j];
}

void nastav_prvek(obrazek obr, int i, int j, short hodnota) // Funkce nastaví hodnotu pixelu na pozici i, j
{
    if (i < 0 || i >= obr.h || j < 0 || j >= obr.w)
    {
        chyba = CHYBA_TYPU;
    }
    obr.data[i][j] = hodnota;
    chyba = BEZ_CHYBY;
}