#include <stdio.h>

int main()
{
    int a = 2, b = 2, c = 0, d = 1, e = 4;

    // Výraz 1
    int vysledek1 = a++ / b-- * d++;
    printf("Vysledek a++ / b-- * d++: %d\n", vysledek1);

    // Výraz 2, ted je a=3, b=1, c=0, d=2, e=4
    int vysledek2 = b-- * c++ + e;
    printf("Vysledek b-- * c++ + e: %d\n", vysledek2);

    // Výraz 3 ted je a=3, b=0, c=1, d=2, e=4
    int vysledek3 = -b + --c;
    printf("Vysledek -b + --c: %d\n", vysledek3);

    // Výraz 4 ted je a=3, b=0, c=0, d=2, e=4
    printf("%i\n", a);
    int vysledek4 = ++a + a--;
    printf("Vysledek ++a + a--: %d\n", vysledek4);

    // Výraz 5 ted je a=3, b=0, c=0, d=2, e=4
    if (a != 0 && c != 0)
    {
        int vysledek5 = c / a * d++ / c--;
        printf("Výsledek výrazu c / a * d++ / c--: %d\n", vysledek5);
    }
    else
    {
        printf("Chyba: deleni nulou\n");
    }
    // Výraz 6 ted je a=3, b=0, c=-1, d=2, e=4
    a %= b = d = 1 + e / 2;
    printf("Vysledek a %%= b = d = 1 + e / 2: a = %d, b = %d, d = %d\n", a, b, d);

    return 0;
}
