#include <stdio.h>

int main(){
    int pole[] = {1, 2, 3};
    int *p_pole = pole;

     /* pole i p_pole ukazuji na stejny kus pameti */
     printf("%p %p\n", *pole, *p_pole);

     /* ztratili jsme informaci o velikosti */
     printf("%d %d\n", sizeof(pole), sizeof(p_pole));
    return 0;
}




