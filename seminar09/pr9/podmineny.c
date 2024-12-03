#include <stdio.h>

#define ENG 1

#ifdef ENG
#define ERROR "error"
#else
#define ERROR "chyba"
#endif

int main()
{
    printf("%s", ERROR);
    return 0;
}
