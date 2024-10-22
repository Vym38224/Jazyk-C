#include <stdio.h>

// Vytvořte union a strukturu se stejnými položkami a pomocí sizeof(), zjistěte jejich velikost.

typedef struct
{
    int a;
    char b;
} S;

typedef union
{
    int a;
    char b;
} U;

int main()
{

    U u;
    S s;
    printf("Size of union: %d\n", sizeof(u));
    printf("Size of int: %d\n", sizeof(u.a));
    printf("Size of char: %d\n", sizeof(u.b));
    printf("Size of items in union: %d\n", sizeof(u.a) + sizeof(u.b));
    printf("\n");
    printf("Size of struct: %d\n", sizeof(s));
    printf("Size of int: %d\n", sizeof(s.a));
    printf("Size of char: %d\n", sizeof(s.b));
    printf("Size of items in struct: %d\n", sizeof(s.a) + sizeof(s.b));

    return 0;
}