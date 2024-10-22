#include <stdio.h>
typedef union{
    short pocet;
    float vaha;
    float objem;
} mnozstvi;

typedef struct{
    char nazev[20];
    mnozstvi mnozstvi;
} polozka;

int main(){
    polozka kosik[3];

    strcpy(kosik[0].nazev,"mrkev");
    kosik[0].mnozstvi.vaha = 0.5;

    strcpy(kosik[1].nazev,"mleko");
    kosik[1].mnozstvi.objem = 1.0;

    strcpy(kosik[2].nazev,"okurka");
    kosik[2].mnozstvi.pocet = 2;

    printf("%s %f\n", kosik[0].nazev, kosik[0].mnozstvi.vaha);
    printf("%s %f\n", kosik[1].nazev, kosik[1].mnozstvi.objem);
    printf("%s %d\n", kosik[2].nazev, kosik[2].mnozstvi.pocet);

   return 0;
}




