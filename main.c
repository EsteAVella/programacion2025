#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clase1.h"
#include "clase2.h"
#define TOL 0.5
#define EL 5
#define TAM 25

int main()
{
    char vec[TAM] = {"hola copia mundo"};
    char *pf;
    char *pi;
    char *texto = vec;
    /*
    char pc[TAM];
    mostrarVecPos(vec,pf);
    //PREGUNTAR POR ESTO QUE SE PASA EL SEGMENTACION FAULT;

    printf("la cantidad de espacios de %s, es : %d \n", vec, mStrlen(vec));

    printf("La copia de :::: %s :::: es :::: %s ::::\n", vec, mStrcpy(pc, vec));

    printf("La palabra :::: %s :::: \n", vec);

    */
    pi = vec;

    printf("PRIMERA: \n");
    texto = proxPal(texto,&pi,&pf);
    mostrarVecPos(pi, pf);


    printf("SEGUNDA:\n");
    texto = proxPal(texto,&pi,&pf);
    mostrarVecPos(pi, pf);

    printf("TERCERA\n");
    texto = proxPal(texto,&pi,&pf);
    mostrarVecPos(pi, pf);

    return 0;
}
