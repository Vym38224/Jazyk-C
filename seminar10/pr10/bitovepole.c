#include <stdio.h>
#define READ 0x8
#define WRITE 0x10
#define DELETE 0x20

typedef struct
{
    unsigned zacatek : 3; // bity od 0 do 2
    unsigned read : 1;    // bit 3
    unsigned write : 1;   // bit 4
    unsigned delete : 1;  // bit 5
} STAV

    int
    main()
{
}
