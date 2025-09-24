#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clase1.h"
#include "clase2.h"
#define TOL 0.5
#define EL 5
#define TAM 25
#define FIL 10
#define COL 10

int main()
{
    char vec[TAM] = {"hola"};
    char vec2[TAM] = {" mundo"};
    char *pf;
    char *pi;
    char *texto = vec;

    int mat [FIL][COL] = {
                         {1,2,3},
                         {4,5,6},
                         {7,8,9}
    };

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

    printf("%s \n", mStrconcat(vec,vec2));

    int fil = 3;
    int col = 3;
    imprimirMatriz(mat,fil,col);

    return 0;
}
