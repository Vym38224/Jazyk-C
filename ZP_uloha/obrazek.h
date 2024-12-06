#ifndef OBRAZEK_H
#define OBRAZEK_H

typedef struct
{
    int h;        // výška obrázku
    int w;        // šířka obrázku
    short **data; // dvourozměrné pole pro uložení hodnot pixelů
} obrazek;

typedef enum
{
    NEGATIV,        // negativ - jeden nepovinný argument
    ZMENA_JASU,     // změna jasu - jeden nepovinný argument
    ZMENA_KONTRASTU // změna kontrastu - dva nepovinné argumenty
} operace;

// Globální proměnná pro uchování stavu chyby
extern int chyba;

// Symbolické konstanty pro chyby
#define BEZ_CHYBY 0
#define CHYBA_ALOKACE 1
#define CHYBA_OTEVRENI 2
#define CHYBA_ZAVRENI 3
#define CHYBA_TYPU 4
#define CHYBA_JINA 5

// Funkce pro vytvoření obrázku
extern obrazek *vytvor_obrazek(int h, int w);

// Další funkce
extern obrazek inicializace(int h, int w);
extern obrazek cerny(int h, int w);
extern void odstran(obrazek obr);
extern void zobraz(obrazek obr);
extern obrazek otoc90(obrazek obr);
extern obrazek morfing(obrazek obr1, obrazek obr2);
extern short min(obrazek obr);
extern short max(obrazek obr);
extern obrazek jasova_operace(obrazek obr, operace o, ...);
extern obrazek nacti_ze_souboru(const char *soubor);
extern void uloz_do_souboru(obrazek obr, const char *soubor);

// Pomocné funkce
extern int vyska(obrazek obr);
extern int sirka(obrazek obr);
extern short prvek(obrazek obr, int i, int j);
extern void nastav_prvek(obrazek obr, int i, int j, short hodnota);

#endif
