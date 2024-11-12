// Napište program, který pro dané přirozené n spočítá sumu: 1! + (1 + 2)! + (1 + 2 + 3)! + ... + (1 + 2 + ... + n)!

#include <stdio.h>

int factorial(int n)
{
    int i;
    int fact = 1;
    for (i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    int n = 2;
    int sum = 0;
    int i, j;

    for (i = 1; i <= n; i++)
    {
        int temp = 0;
        for (j = 1; j <= i; j++)
        {
            temp += j;
        }
        sum += factorial(temp);
    }
    printf("Suma je %d\n", sum);

    return 0;
}
