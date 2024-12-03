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
        return NULL;
    }
    obr->h = h;
    obr->w = w;
    obr->data = (short **)malloc(h * sizeof(short *));
    if (obr->data == NULL)
    {
        chyba = CHYBA_ALOKACE;
        return NULL;
    }
    for (int i = 0; i < h; i++)
    {
        obr->data[i] = (short *)malloc(w * sizeof(short));
        if (obr->data[i] == NULL)
        {
            chyba = CHYBA_ALOKACE;
            return NULL;
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
    obrazek obr = inicializace(h, w);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            obr.data[i][j] = 0;
        }
    }
    return obr;
}

// Funkce pro odstranění obrázku
void odstran_obrazek(obrazek obr)
{
    for (int i = 0; i < obr.h; i++)
    {
        free(obr.data[i]);
    }
    free(obr.data);
}

// Funkce pro zobrazení obrázku
void zobraz(obrazek obr)
{
    for (int i = 0; i < obr.h; i++)
    {
        for (int j = 0; j < obr.w; j++)
        {
            switch (obr.data[i][j])
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
                printf("?");
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
    obrazek obr_otoc90 = inicializace(obr.w, obr.h);

    for (int i = 0; i < obr.h; i++)
    {
        for (int j = 0; j < obr.w; j++)
        {
            int nova_radkova_pozice = obr.w - 1 - j;
            int nova_sloupcova_pozice = i;
            obr_otoc90.data[nova_radkova_pozice][nova_sloupcova_pozice] = obr.data[i][j];
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
        return inicializace(0, 0);
        exit(1);
    }

    obrazek obr3 = inicializace(obr1.h, obr1.w);

    for (int i = 0; i < obr1.h; i++)
    {
        for (int j = 0; j < obr1.w; j++)
        {
            obr3.data[i][j] = (obr1.data[i][j] + obr2.data[i][j]) / 2;
        }
    }
    chyba = BEZ_CHYBY;
    return obr3;
}

// Funkce pro získání minimální hodnoty pixelu
short min(obrazek obr)
{
    short min_val = obr.data[0][0];
    for (int i = 0; i < obr.h; i++)
    {
        for (int j = 0; j < obr.w; j++)
        {
            if (obr.data[i][j] < min_val)
            {
                min_val = obr.data[i][j];
            }
        }
    }
    chyba = BEZ_CHYBY;
    return min_val;
}

// Funkce pro získání maximální hodnoty pixelu
short max(obrazek obr)
{
    short max_val = obr.data[0][0];
    for (int i = 0; i < obr.h; i++)
    {
        for (int j = 0; j < obr.w; j++)
        {
            if (obr.data[i][j] > max_val)
            {
                max_val = obr.data[i][j];
            }
        }
    }
    chyba = BEZ_CHYBY;
    return max_val;
}

// Funkce pro jasovou operaci
obrazek jasova_operace(obrazek obr, operace o, ...)
{
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

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            fscanf(f, "%hi", &obr.data[i][j]);
        }
    }

    fclose(f);
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

    fprintf(f, "%i %i\n", obr.h, obr.w);

    for (int i = 0; i < obr.h; i++)
    {
        for (int j = 0; j < obr.w; j++)
        {
            fprintf(f, "%hi ", obr.data[i][j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
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