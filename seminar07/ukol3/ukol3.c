
#include <stdio.h>

int main()
{
    int i = 5;

    printf("%d\n", i == 8);
    printf("%d\n", i = 8);
    printf("%d\n", i == 8);

    return 0;
}