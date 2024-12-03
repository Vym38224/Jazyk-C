#include <stdio.h>

int main(){
    int karta = 1;

    if(karta > 1){
        karta = karta - 1;
        if(karta < 7)
            printf("Mala karta");
    else
        printf("Eso");

    return 0;
}
