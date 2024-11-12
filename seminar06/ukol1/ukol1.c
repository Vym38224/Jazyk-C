// Napište program, který nalezne všechna čtyřciferná čísla, která jsou dělitelná číslem, které dostaneme jako sumu čísla tvořeného první a druhou číslicí a čísla tvořeného třetí a
// čtvrtou číslicí. Například číslo 3417 je dělitelné číslem 34 + 17. Vhodné části algoritmu realizujte pomocí funkcí.

#include <stdio.h>

int delitelne(int n)
{
    int a = n / 1000;
    int b = (n / 100) % 10;
    int c = (n / 10) % 10;
    int d = n % 10;
    return n % ((a * 10 + b) + (c * 10 + d)) == 0;
}

int main()
{
    for (int i = 1000; i < 10000; i++)
    {
        if (delitelne(i))
        {
            printf("%d\n", i);
        }
    }
    return 0;
}