#include <stdio.h>

typedef struct
{
    int x;
    int y;
    int pole[2];
} struktura;

int main()
{
    struktura m;          // zde můžeme deklarovat strukturu bez inicializace: struktura m = {10, 2, {10, 2}};
    m = {10, 2, {10, 2}}; // takle mužeme inicializovat strukturu jen při deklaraci
    return 0;
}
