#include <stdio.h>
#define na_mala(c) (c | 32)

int main(void)
{
    printf("%c %c", 'A', na_mala('A'));
}
