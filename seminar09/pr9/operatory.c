#include <stdio.h>

#define plus(X,Y) printf("%s + %s = %d", #X, #Y, (X) + (Y))
/* plus(3,2);
   printf("%s + %s = %d", "3", "2", (3) + (2));*/

#define var(X) promenna ## X
/* var(10)
   promenna10 */


int main(){
    /* plus(3,2);
        printf("%s + %s = %d", "3", "2", (3) + (2));*/
    plus(3,2);

    /* var(5)
   promenna5 */

   int var(5) = 10;

   printf("\npromenna = %i", promenna5);
}
