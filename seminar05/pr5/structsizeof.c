#include <stdio.h>
struct struktura{
    float a;
    char b;
    int c;
};

int main(){
   printf("Velikost struktury: %i\n", sizeof(struct struktura));
   printf("Velikost polozek: %i\n", sizeof(float) + sizeof(int) + sizeof(char));

   return 0;
}
