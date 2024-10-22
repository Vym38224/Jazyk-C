#include <stdio.h>
int main()
{
    int pole[] = {1, 2, 3};
    int *prvek = pole;
    pole[0] = 2;
    pole[1] = pole[2];
    pole[2] = *prvek;
    printf("%d", pole[2]);
    return 0;
}
