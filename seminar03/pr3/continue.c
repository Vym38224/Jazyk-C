#include <stdio.h>


int main(){
    int j;
    for(j = 1; j < 10; j = j + 1){
        if((j % 3) == 0)
            continue;
        printf("%d ", j);
    }
    return 0;
}

