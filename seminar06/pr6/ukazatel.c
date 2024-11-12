#include <stdio.h>



double polynomA(double x){
    return 3*x*x + 2*x + 1;
}

int main(){
    double (*ptr_polynom)(double) = polynomA;

    printf("%f", ptr_polynom(-1));
    return 0;
}
