#include <stdio.h>

int main(){
    /* jednorozmerne pole */
    int pole1[4] = {1, 2, 3, 4};

    /* dvourozmerne */
    int pole2[2][3] = {{1, 2, 3}, {1, 2, 3}};

    /* trojrozmerne */
    int pole3[2][3][4] = {{{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}},
                          {{5, 6, 7, 8}, {5, 6, 7, 8}, {5, 6, 7, 8}}};

    /* jake cislo se vypise? */
    printf("%d ", pole3[1][0][1]);

    return 0;
}




