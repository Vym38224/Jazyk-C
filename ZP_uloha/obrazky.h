#ifndef OBRAZKY_H
#define OBRAZKY_H

typedef struct {
    int h;      // výška obrázku
    int w;      // šířka obrázku
    short **data; // dvourozměrné pole pro uložení hodnot pixelů
} obrazek;

typedef enum {
    NEGATIV,
    ZMENA_JASU,
    ZMENA_KONTRASTU
} operace;

// Symbolické konstanty pro chyby
#define BEZ_CHYBY 0
#define CHYBA_ALOKACE 1
#define CHYBA_OTEVRENI 2
#define CHYBA_ZAVRENI 3
#define CHYBA_TYPU 4
#define CHYBA_JINA 5

// Globální proměnná pro uchování stavu chyby
extern int chyba;

// Funkce pro vytvoření a zrušení obrázku
obrazek* vytvor_obrazek(int h, int w);
void zrus_obrazek(obrazek *img);

// Funkce pro nastavení a získání hodnoty pixelu
void nastav_pixel(obrazek *img, int x, int y, short hodnota);
short ziskej_pixel(obrazek *img, int x, int y);

// Další funkce
obrazek inicializace(int h, int w);
obrazek cerny(int h, int w);
void odstran(obrazek obr);
void zobraz(obrazek obr);
obrazek otoc90(obrazek obr);
obrazek morfing(obrazek obr1, obrazek obr2);
short min(obrazek obr);
short max(obrazek obr);
obrazek jasova_operace(obrazek obr, operace o, ...);
obrazek nacti_ze_souboru(const char *soubor);
void uloz_do_souboru(obrazek obr, const char *soubor);

// Pomocné funkce
int vyska(obrazek obr);
int sirka(obrazek obr);
short prvek(obrazek obr, int i, int j);
void nastav_prvek(obrazek obr, int i, int j, short hodnota);

#endif // OBRAZKY_H