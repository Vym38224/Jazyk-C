// program spočíta 25% daň a vypíše novou cenu

#include <stdio.h>

int main()
{
    float cena;
    float nova_cena;
    float dph = 0.25;

    printf("Zadej cenu: ");
    scanf("%f", &cena);

    nova_cena = cena * (1 + dph);

    printf("Nova cena je: %.2f\n", nova_cena);

    return 0;
}