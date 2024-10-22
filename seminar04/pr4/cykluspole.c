#include <stdio.h>

int main(){
    int pole[20];
    int i;

    for(i = 0; i < 20; i++){
        pole[i] = 2*i;
    }

    for(i = 0; i < 20; i++){
        printf("%d, ", pole[i]);
    }

    return 0;
}
