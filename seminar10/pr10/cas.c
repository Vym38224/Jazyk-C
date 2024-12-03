#include <stdio.h>

typedef struct
{
    unsigned hodiny : 5;  // 5 bitu - cisla od 0 do 31
    unsigned minuty : 6;  // 6 bitu - cisla od 0 do 63
    unsigned vteriny : 6; // 6 bitu - cisla od 0 do 63
} CAS;

CAS cas_pole(int h, int m, int v)
{
    CAS cas;
    cas.hodiny = h;
    cas.minuty = m;
    cas.vteriny = v;
    return cas;
}

void vypis(CAS c)
{
    printf("%i : %i : %i", c.hodiny, c.minuty, c.vteriny);
}

int main()
{
    CAS cas = cas_pole(10, 30, 0);
    printf("cas jako pole: %i \n", cas);
    vypis(cas);
}
