#include <stdio.h>


int main(){
    int i, j, k;
    int x[10]={1,2,3,4,5,1,6,7,8,9};


    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            for (k = 0; k < 10; k++){
                /* x je pole a x[k] vraci jeho k-ty prvek */
                if (x[k] == 0)
                    goto chyba;
                printf("%d ", (x[i] + x[j]) / x[k]);
            }
        }
    }


    return 0;

    chyba:
    printf("\nNelze delit nulou\n");
    return 1;
}
