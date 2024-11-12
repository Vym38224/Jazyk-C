#include <stdio.h>
int fakt(int n)
{
    if (n <= 0)
        return 1;
    return n * fakt(n - 1);
}

int main()
{
    int n = 10;
    printf("Faktorial cisla %d je roven %d", n, fakt(n));
    return 0;
}
