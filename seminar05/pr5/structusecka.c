#include <stdio.h>

struct bod{
 float x;
 float y;
 float z;
};

struct usecka{
 struct bod A;
 struct bod B;
};

int main(){
    struct usecka usecka1;

    usecka1.A.x = 10;
    usecka1.A.y = 10;
    usecka1.A.z = 10;

    usecka1.B.x = 5;
    usecka1.B.y = 4;
    usecka1.B.z = 3;

    printf("%f ", usecka1.B.y);

    return 0;
}
