#include <stdio.h>

int main(void)
{
    int i1, i2, j=10;

    i1 = j * 80; //pomalejsi

    i2 = (j << 6) + (j << 4); // rychlejsi

    printf("%i %i", i1, i2);

}
