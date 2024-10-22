#include <stdio.h>
#include <time.h>

void otoc_pole_pointer(int *p, int velikost);
void otoc_pole_array(int p[], int velikost);

#include <stdio.h>

int main() {
    char c;
    int i;
    double d;

    char *pc = &c;
    int *pi = &i;
    double *pd = &d;

    printf("Size of char: %ld bytes\n", (char *)(pc + 1) - pc);
    printf("Size of int: %ld bytes\n", (char *)(pi + 1) - (char *)pi);
    printf("Size of double: %ld bytes\n", (char *)(pd + 1) - (char *)pd);

    return 0;
}

void otoc_pole_pointer(int *p, int velikost) {
    int i;
    int foo;
    for (i = 0; i < velikost / 2; i++) {
        foo = *(p + i);
        *(p + i) = *(p + velikost - i - 1);
        *(p + velikost - i - 1) = foo;
    }
}

void otoc_pole_array(int p[], int velikost) {
    int i;
    int foo;
    for (i = 0; i < velikost / 2; i++) {
        foo = p[i];
        p[i] = p[velikost - i - 1];
        p[velikost - i - 1] = foo;
    }
}