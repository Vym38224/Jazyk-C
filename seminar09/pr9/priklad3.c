#include <stdio.h>
#define JMENO "Marketa"

int main(){
    /* Vypise Moje jmeno je JMENO */
    printf("Moje jmeno je %s\n", JMENO);

    #undef JMENO
    #define JMENO "Trneckova"

    printf("Moje jmeno je %s\n", JMENO);

    return 0;
}
