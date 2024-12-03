#include <stdio.h>

#define PI 3.14

int main()
{
    float r = 3;
    float o = 2 * PI * r; /* o = 2*3.14*r; */
    printf("Obvod kruhu o polomeru %.2f je %.2f\n", r, o);
    return 0;
}
