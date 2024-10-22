#include <stdio.h>

int main(){

    int pole[] = {1,2,3,4,5,6,7,8,9,10};
    int *ptr;

    for (ptr = pole; ptr < pole + 10; ptr++){
        /* hodnota prvku pole */
        printf("Hodnota *ptr = %d\n", *ptr);
        /* adresa prvku pole */
        printf("Adresa ptr = %p\n\n", ptr);
    }


    return 0;
}


