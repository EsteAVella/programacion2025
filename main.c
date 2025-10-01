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
    char vec[] = "holas hola hola mundo hola";
    char *palabra = "hola mundo";

    printf("%s \n",palabra);
    normalizarVec(vec);
    printf("%s \n", vec);
    return 0;
}
