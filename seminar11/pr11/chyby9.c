#include <stdio.h>
int i; // i je globalni promenna, takže se mění vždy, když se změní v jiné funkci

void vykresli_trouhelnik(int n)
{
    for (i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int n = 5;
    for (i = 1; i <= n; i++)
    {
        vykresli_trouhelnik(i);
    }
    return 0;
}
