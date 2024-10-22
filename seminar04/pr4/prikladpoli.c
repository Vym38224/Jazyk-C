#include <stdio.h>

int main()
{
    int pole[5] = {1, 2, 3, 4, 5};

    pole[2] = 10;
    pole[3] = pole[1] + pole[2];
    pole[1] = pole[5]; /*neni uplně ok, protože bere prvek mimo pole. Takže zasahuje do paměti mimo pamět vyhrazenou pro pole*/
    pole[7] = 10;

    return 0;
}
