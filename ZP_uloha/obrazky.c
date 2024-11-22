#include "obrazky.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

// Globální proměnná pro uchování stavu chyby
int chyba = BEZ_CHYBY;

// Funkce pro vytvoření obrázku
obrazek *vytvor_obrazek(int h, int w)
{
}

// Funkce pro inicializaci obrázku
obrazek inicializace(int h, int w)
{
}

// Funkce pro vytvoření černého obrázku
obrazek cerny(int h, int w)
{
}

// Funkce pro odstranění obrázku
void odstran(obrazek obr)
{
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

// Funkce pro otočení obrázku o 90 stupňů
obrazek otoc90(obrazek obr)
{
}

// Funkce pro morfing dvou obrázků
obrazek morfing(obrazek obr1, obrazek obr2)
{
    int h = obr1.h < obr2.h ? obr1.h : obr2.h; // Výška nového obrázku je menší z výšek původních obrázků
    int w = obr1.w < obr2.w ? obr1.w : obr2.w; // Šířka nového obrázku je menší z šířek původních obrázků
    obrazek morfovany = inicializace(h, w);
    if (chyba != BEZ_CHYBY) // Pokud se nepodařilo alokovat paměť, vrátíme prázdný obrázek
        return morfovany;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            morfovany.data[i][j] = (obr1.data[i][j] + obr2.data[i][j]) / 2;
        }
    }
    chyba = BEZ_CHYBY;
    return morfovany;
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
}

// Funkce pro uložení obrázku do souboru
void uloz_do_souboru(obrazek obr, const char *soubor)
{
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
        return;
    }
    obr.data[i][j] = hodnota;
    chyba = BEZ_CHYBY;
}