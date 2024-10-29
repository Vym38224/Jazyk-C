#include <stdio.h>


void f(){
    int x = 0;
    static int y = 0;

    printf("y = %d, x = %d\n", y, x);
    y++;
    x++;
}

int main(){
    f();
    f();
    f();
    f();
    return 0;
}
