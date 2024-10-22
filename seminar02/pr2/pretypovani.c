#include <stdio.h>

int main()
{
  int i = 10, j = 4, k;
  float f;

  /* k i f = 2, protoze i a j jsou typu int, podil je typu int.
  Vysledek je roven celociselnemu deleni. */
  k = i / j;
  f = i / j;

  printf("k = %d \n f = %f\n", k, f);

  /* f bude mit hodnotu 2.5, protoze citatel je float,
   podil je take typu float.
     k bude rovno 2, i pres to, ze vysledek prave strany je
     2.5 . k je typu int, dochazi zde k implicitni konverzi.
     Desetinna cast cisla se odstrani. */
  k = (float)i / j;
  f = (float)i / j;

  /*printf("k = %d \n f = %f\n", k, f);*/

  return 0;
}
