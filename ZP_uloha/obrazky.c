#include "obrazky.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

// Globální proměnná pro uchování stavu chyby
int chyba = BEZ_CHYBY;

// Funkce pro vytvoření obrázku
obrazek* vytvor_obrazek(int h, int w) {
    obrazek *img = (obrazek*)malloc(sizeof(obrazek));
    if (!img) {
        chyba = CHYBA_ALOKACE;
        return NULL;
    }
    img->h = h;
    img->w = w;
    img->data = (short**)malloc(h * sizeof(short*));
    if (!img->data) {
        free(img);
        chyba = CHYBA_ALOKACE;
        return NULL;
    }
    for (int i = 0; i < h; i++) {
        img->data[i] = (short*)malloc(w * sizeof(short));
        if (!img->data[i]) {
            for (int j = 0; j < i; j++) {
                free(img->data[j]);
            }
            free(img->data);
            free(img);
            chyba = CHYBA_ALOKACE;
            return NULL;
        }
    }
    chyba = BEZ_CHYBY;
    return img;
}

// Funkce pro zrušení obrázku
void zrus_obrazek(obrazek *img) {
    if (!img) {
        chyba = CHYBA_TYPU;
        return;
    }
    for (int i = 0; i < img->h; i++) {
        free(img->data[i]);
    }
    free(img->data);
    free(img);
    chyba = BEZ_CHYBY;
}

// Funkce pro nastavení hodnoty pixelu
void nastav_pixel(obrazek *img, int x, int y, short hodnota) {
    if (!img || x < 0 || x >= img->h || y < 0 || y >= img->w) {
        chyba = CHYBA_TYPU;
        return;
    }
    img->data[x][y] = hodnota;
    chyba = BEZ_CHYBY;
}

// Funkce pro získání hodnoty pixelu
short ziskej_pixel(obrazek *img, int x, int y) {
    if (!img || x < 0 || x >= img->h || y < 0 || y >= img->w) {
        chyba = CHYBA_TYPU;
        return -1;
    }
    chyba = BEZ_CHYBY;
    return img->data[x][y];
}

// Funkce pro inicializaci obrázku
obrazek inicializace(int h, int w) {
    obrazek img;
    img.h = h;
    img.w = w;
    img.data = (short**)malloc(h * sizeof(short*));
    if (!img.data) {
        chyba = CHYBA_ALOKACE;
        return img;
    }
    for (int i = 0; i < h; i++) {
        img.data[i] = (short*)malloc(w * sizeof(short));
        if (!img.data[i]) {
            for (int j = 0; j < i; j++) {
                free(img.data[j]);
            }
            free(img.data);
            chyba = CHYBA_ALOKACE;
            return img;
        }
    }
    chyba = BEZ_CHYBY;
    return img;
}

// Funkce pro vytvoření černého obrázku
obrazek cerny(int h, int w) {
    obrazek img = inicializace(h, w);
    if (chyba != BEZ_CHYBY) return img;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            img.data[i][j] = 0;
        }
    }
    chyba = BEZ_CHYBY;
    return img;
}

// Funkce pro odstranění obrázku
void odstran(obrazek obr) {
    for (int i = 0; i < obr.h; i++) {
        free(obr.data[i]);
    }
    free(obr.data);
    chyba = BEZ_CHYBY;
}

// Funkce pro zobrazení obrázku
void zobraz(obrazek obr) {
    for (int i = 0; i < obr.h; i++) {
        for (int j = 0; j < obr.w; j++) {
            switch (obr.data[i][j]) {
                case 0: printf(" "); break;
                case 1: printf("."); break;
                case 2: printf(":"); break;
                case 3: printf("+"); break;
                case 4: printf("#"); break;
                default: printf("?"); break;
            }
        }
        printf("\n");
    }
    chyba = BEZ_CHYBY;
}

// Funkce pro otočení obrázku o 90 stupňů
obrazek otoc90(obrazek obr) {
    obrazek otoceny = inicializace(obr.w, obr.h);
    if (chyba != BEZ_CHYBY) return otoceny;
    for (int i = 0; i < obr.h; i++) {
        for (int j = 0; j < obr.w; j++) {
            otoceny.data[j][obr.h - 1 - i] = obr.data[i][j];
        }
    }
    chyba = BEZ_CHYBY;
    return otoceny;
}

// Funkce pro morfing dvou obrázků
obrazek morfing(obrazek obr1, obrazek obr2) {
    int h = obr1.h < obr2.h ? obr1.h : obr2.h;
    int w = obr1.w < obr2.w ? obr1.w : obr2.w;
    obrazek morfovany = inicializace(h, w);
    if (chyba != BEZ_CHYBY) return morfovany;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            morfovany.data[i][j] = (obr1.data[i][j] + obr2.data[i][j]) / 2;
        }
    }
    chyba = BEZ_CHYBY;
    return morfovany;
}

// Funkce pro získání minimální hodnoty pixelu
short min(obrazek obr) {
    short min_val = obr.data[0][0];
    for (int i = 0; i < obr.h; i++) {
        for (int j = 0; j < obr.w; j++) {
            if (obr.data[i][j] < min_val) {
                min_val = obr.data[i][j];
            }
        }
    }
    chyba = BEZ_CHYBY;
    return min_val;
}

// Funkce pro získání maximální hodnoty pixelu
short max(obrazek obr) {
    short max_val = obr.data[0][0];
    for (int i = 0; i < obr.h; i++) {
        for (int j = 0; j < obr.w; j++) {
            if (obr.data[i][j] > max_val) {
                max_val = obr.data[i][j];
            }
        }
    }
    chyba = BEZ_CHYBY;
    return max_val;
}

// Funkce pro jasovou operaci
obrazek jasova_operace(obrazek obr, operace o, ...) {
    va_list args;
    va_start(args, o);
    obrazek novy = inicializace(obr.h, obr.w);
    if (chyba != BEZ_CHYBY) return novy;
    switch (o) {
        case NEGATIV:
            for (int i = 0; i < obr.h; i++) {
                for (int j = 0; j < obr.w; j++) {
                    novy.data[i][j] = 4 - obr.data[i][j];
                }
            }
            break;
        case ZMENA_JASU: {
            int jas = va_arg(args, int);
            for (int i = 0; i < obr.h; i++) {
                for (int j = 0; j < obr.w; j++) {
                    novy.data[i][j] = obr.data[i][j] + jas;
                    if (novy.data[i][j] < 0) novy.data[i][j] = 0;
                    if (novy.data[i][j] > 4) novy.data[i][j] = 4;
                }
            }
            break;
        }
        case ZMENA_KONTRASTU: {
            double kontrast = va_arg(args, double);
            int jas = va_arg(args, int);
            for (int i = 0; i < obr.h; i++) {
                for (int j = 0; j < obr.w; j++) {
                    novy.data[i][j] = (short)(obr.data[i][j] * kontrast + jas);
                    if (novy.data[i][j] < 0) novy.data[i][j] = 0;
                    if (novy.data[i][j] > 4) novy.data[i][j] = 4;
                }
            }
            break;
        }
    }
    va_end(args);
    chyba = BEZ_CHYBY;
    return novy;
}

// Funkce pro načtení obrázku ze souboru
obrazek nacti_ze_souboru(const char *soubor) {
    FILE *file = fopen(soubor, "r");
    if (!file) {
        chyba = CHYBA_OTEVRENI;
        return (obrazek){0, 0, NULL};
    }

    int h, w;
    fscanf(file, "%d %d", &h, &w);
    obrazek img = inicializace(h, w);
    if (chyba != BEZ_CHYBY) {
        fclose(file);
        return img;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            fscanf(file, "%hd", &img.data[i][j]);
        }
    }
    if (fclose(file) != 0) {
        chyba = CHYBA_ZAVRENI;
    } else {
        chyba = BEZ_CHYBY;
    }
    return img;
}

// Funkce pro uložení obrázku do souboru
void uloz_do_souboru(obrazek obr, const char *soubor) {
    FILE *file = fopen(soubor, "w");
    if (!file) {
        chyba = CHYBA_OTEVRENI;
        return;
    }

    fprintf(file, "%d %d\n", obr.h, obr.w);
    for (int i = 0; i < obr.h; i++) {
        for (int j = 0; j < obr.w; j++) {
            fprintf(file, "%hd ", obr.data[i][j]);
        }
        fprintf(file, "\n");
    }
    if (fclose(file) != 0) {
        chyba = CHYBA_ZAVRENI;
    } else {
        chyba = BEZ_CHYBY;
    }
}

// Pomocné funkce
int vyska(obrazek obr) {
    return obr.h;
}

int sirka(obrazek obr) {
    return obr.w;
}

short prvek(obrazek obr, int i, int j) {
    if (i < 0 || i >= obr.h || j < 0 || j >= obr.w) {
        chyba = CHYBA_TYPU;
        return -1;
    }
    chyba = BEZ_CHYBY;
    return obr.data[i][j];
}

void nastav_prvek(obrazek obr, int i, int j, short hodnota) {
    if (i < 0 || i >= obr.h || j < 0 || j >= obr.w) {
        chyba = CHYBA_TYPU;
        return;
    }
    obr.data[i][j] = hodnota;
    chyba = BEZ_CHYBY;
}