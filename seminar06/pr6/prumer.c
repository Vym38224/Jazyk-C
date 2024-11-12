#include <stdio.h>
#include <stdarg.h>

double prumer(int pocet, ...)
{
    double soucet = 0;
    int i;
    va_list parametry;
    va_start(parametry, pocet);
    for (i = 0; i < pocet; i++)
    {
        soucet += va_arg(parametry, double);
    }
    va_end(parametry);
    return soucet / pocet;
}

int main()
{
    printf("%f \n", prumer(5, 1.2, 3.4, 5.6, 7.8, 9.0));
    return 0;
}
