#include <stdio.h>

int main(){

    int pole[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr;
    int i;

    ptr = pole;

    for (i = 0; i < 10; i++){
        /* hodnota prvku pole */
        printf("Hodnota *ptr = %d\n", *(ptr + i));
        /* adresa prvku pole */
        printf("Adresa ptr = %p\n\n", (ptr + i));
    }

    return 0;
}



