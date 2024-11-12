#include <stdio.h>
void funkceA();
void funkceB();
void funkceC();

void funkceA(){
    funkceB();
}

void funkceB(){
    funkceC();
}

void funkceC(){
    if(3 < 2)
        funkceA();
}

int main(){
    funkceA();
    return 0;
}
