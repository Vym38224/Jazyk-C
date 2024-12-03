#include <stdio.h>

int main()
{
    char *karty = "JQK"; // karty je ukazatel na pole znaku, takže karty[0] je 'J', karty[1] je 'Q' a kart[2] je 'K'. Přiklad karty[] = "JQK" fungovat bude
    char karta = karty[2];

    karty[2] = karty[1];
    karty[1] = karty[0];
    karty[0] = karty[2];
    karty[2] = karty[1];
    karty[1] = karta;

    printf("%s", karty);
    return 0;
}
