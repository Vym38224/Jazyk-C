#include <stdio.h>
#define add(x, y) ((x) + (y))
#define plus(x, y) add((x), (y))

int main(){
    printf("Vysledek = %i\n", plus(1, 2));

    return 0;
}
