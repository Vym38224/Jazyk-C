// Napište program, který pro dané přirozené číslo spočítá jeho rozdíl od nejbližšího většíhoprvočísla.

#include <stdio.h>

int prvocislo(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    printf("Zadejte přirozené číslo: ");
    scanf("%d", &n);
    int i = n + 1;
    while (1)
    {
        if (prvocislo(i))
        {
            printf("Rozdíl od nejbližšího většíhoprvočísla je: %d\n", i - n);
            break;
        }
        i++;
    }
    return 0;
}