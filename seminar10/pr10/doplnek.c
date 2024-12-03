#include <stdio.h>

int main(void)
{
    int i = 10, i2;
    unsigned char j = 10, j2;

    i2 = ~i;
    j2 = ~j;

    printf("%i %i \n", sizeof(char), sizeof(int));

    printf("%u %i", i2, j2);

}
