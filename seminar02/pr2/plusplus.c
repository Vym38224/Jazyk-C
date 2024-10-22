#include <stdio.h>

int main()
{
    int a = 10;
    int b = 10;
    a = b++;
    printf("hodnota a je %d a hodnota b je %d \n", a, b);
    a = ++b;
    printf("hodnota a je %d a hodnota b je %d \n", a, b);
    return 0;
}

