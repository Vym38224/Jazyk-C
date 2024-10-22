/*Napište program, který načte písmeno, a rozhodne zda je velké nebo malé. Využijte znalosti ASCII tabulky*/

#include <stdio.h>

int main()
{
    char c;
    printf("Zadejte pismeno: ");
    scanf("%c", &c);

    if (c >= 65 && c <= 90)
    {
        printf("Zadane pismeno je velke.\n");
    }
    else if (c >= 97 && c <= 122)
    {
        printf("Zadane písmeno je malé.\n");
    }
    else
    {
        printf("Zadane pismeno neni pismeno.\n");
    }

    return 0;
}