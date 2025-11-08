#include <stdio.h>
#include "matriz.h"

int sumarDiagonalSup2(int mat[3][3],int fil, int col){

    int calc = 0;

    for(int i = 0; i < fil; i++){
        for(int j = col-1; j > i; j--){
            if(j != i ){
                calc += mat[i][j];
            }
        }
    }
    return calc;
}
int sumarDiagonalInf2(int mat[3][3],int fil,int col){
    int calc = 0;

    for(int j = col-1; j > 0; j--){
        for(int i = j-1; i >= 0; i--){
            calc += mat[j][i];
        }
    }

    return calc;
}

void imprimirMatriz2(int m[][3], int filas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < 3; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

void transponerMatriz2(int m[3][3],int fila, int colu){

    int aux = 0;

    for(int i = 0; i < fila; i++){
        for(int j = colu - 1; j > i; j--){
            aux = m[j][i];
            m[j][i] = m[i][j];
            m[i][j] = aux;
        }
    }
}


