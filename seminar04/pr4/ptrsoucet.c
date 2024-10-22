#include <stdio.h>

int main()
{

    char *ptr_c = 10;
    int *ptr_i = 10;
    float *ptr_f = 10;

    printf("Adresa ptr_c = %i\n", ptr_c);
    printf("sizeof(char) = %i\n", sizeof(char));
    printf("Adresa ptr_c + 1 = %i\n\n", ptr_c + 1);

    printf("Adresa ptr_i = %i\n", ptr_i);
    printf("sizeof(int) = %i\n", sizeof(int));
    printf("Adresa ptr_i + 1 = %i\n\n", ptr_i + 1);

    printf("Adresa ptr_f = %i\n", ptr_f);
    printf("sizeof(float) = %i\n", sizeof(float));
    printf("Adresa ptr_f + 1 = %i\n\n", ptr_f + 1);

    return 0;
}
