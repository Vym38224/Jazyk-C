#include <stdio.h>

int main()
{
    FILE *f;
    char c = 'f';
    char str[100];
    int i;

    f = fopen("cisla.txt", "r");

    if (f == NULL)
    {
        printf("Nepodarilo se otevrit soubor.");
        return 1;
    }

    /* cteni znaku */
    for (i = 0; i < 100; i++)
    {
        c = getc(f);
        printf("%c", c);
    }

    /* cteni radku */
    printf("\n\n");
    fgets(str, 100, f);
    printf("%s", str);

    fclose(f);
    return 0;
}
