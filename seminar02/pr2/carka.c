#include <stdio.h>

int main(){
    int i = 2, j = 3; /* Toto neni operator carky */

    j = (i++, i - j);

    printf("i = %d, j = %d", i, j);
    return 0;
}
