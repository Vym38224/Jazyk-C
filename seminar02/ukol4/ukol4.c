/*Napište program, který načte velké písmeno, a vypíše jej jako malé. Využijte znalosti ASCII tabulky*/

#include <stdio.h>

int main()
{
    char c;
    printf("Zadejte velke pismeno: ");
    scanf("%c", &c);

    printf("Tady máte malé písmeno: %c\n", c + 32);

    return 0;
}