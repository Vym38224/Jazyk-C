#include <stdio.h>
/*Napište program, který vypíše hodnotu matematického výrazu*/

int main()
{
    int result;
    result = (3 / 2.) + 12 + (5 * 5 - 2 * 2) / 6.;

    printf("Výsledek výrazu je: %d", result);

    return 0;
}