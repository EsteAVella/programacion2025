#include <stdio.h>
#define MAXLINE 100
#include "repaso.h"
#include "main.h"

int main()
{

    int vec[6] = { 2,5,1,7,4,3};
    unsigned ce = 6;

    printf("Previo al ordenar : \n");
    imprimirVec(vec,ce);

    printf("despues del ordenar : \n");
    ordenar(vec,ce);
    imprimirVec(vec,ce);

    // miMap(vec,ce,sizeof(int),sumaUno);
    return 0;

}
