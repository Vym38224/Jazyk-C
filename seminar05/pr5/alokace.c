#include <stdio.h>

int main(){
    int *pole1;
    int *pole2 = malloc(2*sizeof(int));
    int pole3[2];

    pole1 = (int *)malloc(2*sizeof(int));

    printf("velikost pole1 je %d \n", sizeof(pole1));
    printf("velikost pole3 je %d \n", sizeof(pole3));

    pole2 = realloc(pole2, 4);


    free(pole1);
    free(pole2);
    free(pole3);

    return 0;
}
