#include <stdio.h>
#define liche(x) (1 & (x))

int main(void)
{
    if (liche(121))
        printf("liche \n");
    else
        printf("sude \n");
    return 0;
}
