#include <stdio.h>

int main(){

    int i = 10, j = 4, k;
    float f, g = 10.0, h;

    /* k i f jsou rovny 2, protoze i a j jsou typu int, podil je
     typu int. Vysledek dostaneme odstranenim  desetinne casti */
    k = i / j;
    f = i / j;

    //printf("k = %d \n f = %f\n", k, f);

    /* f bude mit hodnotu 2.5, protoze g je float,
     podil je take typu float. */
    f = g / j;

     //printf("f = %f\n", f);

    /* k bude rovno 2, ztrati se desetinna cast. */
    k = f;
    // printf("k = %d", k);

    /* h bude rovno 0.5. Proc? */
    h = f - k;
     printf("h = %f\n", h);

}
