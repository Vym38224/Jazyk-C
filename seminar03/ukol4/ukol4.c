#include <stdio.h>
/*pro zadané číslo od 1 do 10 vypíše posloupnost čísel od zadaného po 1.(switch)*/
int main()
{
    int a;
    printf("Zadejte číslo: ");
    scanf("%d", &a);

    switch (a)
    {
    case 10:
        printf("%d ", a--);
    case 9:
        printf("%d ", a--);
    case 8:
        printf("%d ", a--);
    case 7:
        printf("%d ", a--);
    case 6:
        printf("%d ", a--);
    case 5:
        printf("%d ", a--);
    case 4:
        printf("%d ", a--);
    case 3:
        printf("%d ", a--);
    case 2:
        printf("%d ", a--);
    case 1:
        printf("%d\n", a);
        break;
    default:
        printf("Chyba: Zadejte číslo od 1 do 10.\n");
    }
    return 0;
}