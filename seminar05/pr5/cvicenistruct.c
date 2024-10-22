#include <stdio.h>

typedef struct{
    char* popis;
    float hodnota;
} lup;

typedef struct{
    lup *lup;
    char *sekvence;
} kombinace;

typedef struct{
    kombinace cislo;
    char *vyrobce;
} sejf;

int main(){
    lup zlato = {"ZLATO!", 1000000.0};
    kombinace cislo = {&zlato, "1234"};
    sejf s  = {cislo,"SEJF2021"};

    return 0;
}
