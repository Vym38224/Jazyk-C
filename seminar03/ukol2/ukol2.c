#include <stdio.h>
/*pro zadaný rok, zda je přestupný*/
int main()
{
    int rok;
    printf("Zadejte rok: ");
    scanf("%d", &rok);
    if ((rok % 4 == 0 && rok % 100 != 0) || rok % 400 == 0 && rok % 100 == 0)
    {
        printf("Rok %d je přestupný.\n", rok);
    }
    else
    {
        printf("Rok %d není přestupný.\n", rok);
    }

    return 0;
}
