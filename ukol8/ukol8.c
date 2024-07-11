#include <stdio.h>

int main() {
    int a = 3;
    int b = 2;
    int c = 12;
    int d = 5;
    int e = 6;

    int result = a/b + c + (d * d)/e - (b * b)/e;
    
    printf("Výsledek výrazu je: %d\n", result);
    
    return 0;
}