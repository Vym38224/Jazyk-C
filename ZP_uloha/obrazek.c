#include "obrazek.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

// Globální proměnná pro uchování stavu chyby
int chyba = BEZ_CHYBY;

// Funkce pro vytvoření obrázku
obrazek *vytvor_obrazek(int h, int w)
{
    obrazek *obr = (obrazek *)malloc(sizeof(obrazek));
    if (obr == NULL)
    {
        chyba = CHYBA_ALOKACE;
    }
    obr->h = h;
    obr->w = w;
    obr->data = (short **)malloc(h * sizeof(short *));
    if (obr->data == NULL)
    {
        chyba = CHYBA_ALOKACE;
    }
    for (int i = 0; i < h; i++)
    {
        obr->data[i] = (short *)malloc(w * sizeof(short));
        if (obr->data[i] == NULL)
        {
            chyba = CHYBA_ALOKACE;
        }
    }
    chyba = BEZ_CHYBY;
    return obr;
}

// Funkce pro inicializaci obrázku. Vytvoři obrazek o velikosti h × w včetně alokace paměti pro data
obrazek inicializace(int h, int w)
{
    obrazek obr;
    obr.h = h;
    obr.w = w;
    // Alokace paměti pro řadky
    obr.data = (short **)malloc(h * sizeof(short *));
    if (obr.data == NULL)
    {
        chyba = CHYBA_ALOKACE;
        free(obr.data);
        return obr;
    }

    // Alokace paměti pro sloupce
    for (int i = 0; i < h; i++)
    {
        obr.data[i] = (short *)malloc(w * sizeof(short));
        if (obr.data[i] == NULL)
        {
            chyba = CHYBA_ALOKACE;
            for (int j = 0; j < i; j++)
            {
                free(obr.data[j]);
            }
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
    for (int i = 0; i < vyska(obr_cerny); i++)
    {
        for (int j = 0; j < sirka(obr_cerny); j++)
        {
            nastav_prvek(obr_cerny, i, j, 0);
        }
    }
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
    if (vyska(obr1) != vyska(obr2) || sirka(obr1) != sirka(obr2))
    {
        chyba = CHYBA_TYPU;
    }
    else
    {
        obrazek obr3 = inicializace(vyska(obr1), sirka(obr1));
        for (int i = 0; i < vyska(obr1); i++)
        {
            for (int j = 0; j < sirka(obr1); j++)
            {
                nastav_prvek(obr3, i, j, (prvek(obr1, i, j) + prvek(obr2, i, j)) / 2);
            }
        }
        chyba = BEZ_CHYBY;
        return obr3;
    }
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

    switch (o)
    {
    case 0: // NEGATIV
        for (int i = 0; i < vyska(obr); i++)
        {
            for (int j = 0; j < sirka(obr); j++)
            {
                nastav_prvek(obr2, i, j, 4 - prvek(obr, i, j));
            }
        }
        break;
    case 1: // ZMENA_JASU
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
    case 2: // ZMENA_KONTRASTU
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
        exit(1);
    }

    int h, w;
    fscanf(f, "%i %i", &h, &w);
    obrazek obr = inicializace(h, w);

    for (int i = 0; i < vyska(obr); i++)
    {
        for (int j = 0; j < sirka(obr); j++)
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
        exit(1);
    }

    fprintf(f, "%i %i\n", vyska(obr), sirka(obr));

    for (int i = 0; i < vyska(obr); i++)
    {
        for (int j = 0; j < sirka(obr); j++)
        {
            fprintf(f, "%hi ", prvek(obr, i, j));
        }
        fprintf(f, "\n");
    }

    fclose(f);
    chyba = BEZ_CHYBY;
}

// Pomocné funkce
int vyska(obrazek obr)
{
    return obr.h;
}

int sirka(obrazek obr)
{
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