#include <stdio.h>


int main(){
    int a = 5, b = 1, c = 3, foo = 10;

    if (a > b)
        if (b > c)
            foo = b;
        else foo = c;

    printf("foo = %d", foo);


    return 0;

}




