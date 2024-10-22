#include <stdio.h>

int main(){

    int pole[] = {1, 2, 3};

    printf("1. prvek je %d \n", pole[0]);
    printf("1. prvek je %d \n", *pole);

    printf("3. prvek je %d \n", pole[2]);
    printf("3. prvek je %d \n", *pole+2);

    return 0;
}
