#include <stdio.h>

int main(){
    int a = 3, b, *ptr1, *ptr2;

    /* ukazatel ptr1 ukazuje na promennou a  */
    ptr1 = &a;

    /* hodnota b je 5 (*ptr1 je rovna 3) */
    b = *ptr1 + 2;

    /* ptr1 a ptr2 ukazuji na stejne misto */
    ptr2 = ptr1;

    /* zmenime hodnotu na miste, kam ukazuje ptr2 */
    *ptr2 = 5;

    /* hodnota b bude 8 */
    b = a + 3;

    printf("a = %d, b = %d, ptr1 = %p, ptr2 = %p", a, b, ptr1, ptr2);
    return 0;
}


