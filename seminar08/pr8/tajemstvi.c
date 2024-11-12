#include <stdio.h>

int main(){
    char c;
    int i=0;
    while((c=getchar()) != EOF){
        if((i % 4) > 1)
            putc(c,stdout);
        else
            putc(c,stderr);
        i++;
    }
    return 0;
}
