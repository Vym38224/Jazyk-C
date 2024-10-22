/*Napište program, který načte stranu čtverce a vypíše jeho obvod a obsah*/

#include <stdio.h>

int main()
{
    int strana;
    printf("Zadejte stranu ctverce: ");
    scanf("%d", &strana);

    int obvod = 4 * strana;
    int obsah = strana * strana;

    printf("Obvod ctverce je: %d\n", obvod);
    printf("Obsah ctverce je: %d\n", obsah);

    return 0;
}