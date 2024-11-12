// přečte tři malá písmena a vypíše je jako velká v obraceném pořadí

#include <stdio.h>

int main()
{
    int a, b, c;
    char A, B, C;

    printf("Zadej tri mala pismena: ");
    scanf("%c %c %c", &a, &b, &c);

    A = a - 32;
    B = b - 32;
    C = c - 32;

    printf("Velka pismena v obracenem poradi: %c %c %c\n", C, B, A);

    return 0;
}