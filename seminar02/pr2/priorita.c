#include <stdio.h>

int main(){
    int a, b, c;

    /* priklad 1 */
    a = 2;
    b = 4;
    c = a++ - b / 2;

    printf("a = %d, b = %d, c = %d\n", a, b, c);

    /* priklad 2 */
    a = 2;
    b = 4;
    c = a + 2 - b;

    printf("a = %d, b = %d, c = %d\n", a, b, c);


    return 0;
}


