#include <stdio.h>

int main()
{
    int x = 0, y = 0, z = 1;
    /* int x = 0, y = 0, z = 1; */
    /*AND*/
    if ((y != 0) && ((x / y) < z))
    {
        printf("podminka splnena");
    }
    else
    {
        printf("podminka nesplnena");
    }

    /*OR*/
    if ((y == 0) || ((x / y) < z))
    {
        printf("podminka splnena");
    }
    else
    {
        printf("podminka nesplnena");
    }

    /*
    int x = 0, y = 0, z = 1;

    if ( ((x / y) < z)){
        printf("podminka splnena");
    }
    else{
        printf("podminka nesplnena");
    }

    */

    return 0;
}
