#include <stdio.h>
#include <stdarg.h>

void my_printf(char *ret, ...)
{
    int i;
    char format;
    int cislo;
    char znak;
    float descislo;
    va_list argumenty;
    va_start(argumenty, ret);

    for (i = 0; ret[i] != '\0'; i++)
    {
        if (ret[i] == '*')
        {
            i++;
            format = ret[i];

            switch (format)
            {
            case 'i':
                printf("%i", va_arg(argumenty, int));
                break;
            case 'c':
                printf("%c", va_arg(argumenty, int));
                break;
            case 'f':
                printf("%f", va_arg(argumenty, double));
                break;
            }
        }
        else
        {
            printf("%c", ret[i]);
        }
    }
    va_end(argumenty);
}

int main()
{
    char ret[] = "Ahoj *i znak *c desetinne cislo *f";
    my_printf(ret, 5, 'a', 1.5);
    return 0;
}
