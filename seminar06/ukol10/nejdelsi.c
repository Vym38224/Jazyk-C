// Napište program nejdelsi, který vrátí nejdelší (obsahující nejvíce znaků) ze svých argumentů předaných přes příkazovou řádku(terminál).Například : nejdelsi ahoj jak se mas, vypíše ahoj.

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int max = 0;
    int index = 0;
    for (int i = 1; i < argc; i++)
    {
        if (strlen(argv[i]) > max)
        {
            max = strlen(argv[i]);
            index = i;
        }
    }
    printf("%s\n", argv[index]);
    return 0;
}