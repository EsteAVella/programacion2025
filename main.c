#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clase1.h"
#include "clase2.h"
#include "clase5.h"
#include "clase3.h"
#define TOL 0.5
#define EL 5
#define TAM 25
#define FIL 10
#define COL 10
//puedo trabajar con el vector en vivo cuando es asi tengo que dejarle el void

int main()
{
    char cadena[] = "Nj qemh v ljs kraenkqbres; lj oqe qemh es oqevorme sgn ellhs --Istqt Asdmgj";
    char offset[] = "abcdghijkoqtuv";

    printf("%s \t \n\n", cadena);
    eDesencript(cadena,offset);
    printf("%s \n\n", cadena);

    return 0;
}
