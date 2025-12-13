#include <stdio.h>
#define MAXLINE 100
#include "repaso.h"
#include "main.h"

int main()
{
    FILE *pf;
    pf = fopen("datos.txt","r");
    escribirTexto();
    int vec[6] = { 2,5,1,7,4,3};
    unsigned ce = 6;
    printf("Previo al ordenar : \n");
    for(int i = 0; i < ce; i++){
        printf("%d. %d\n",i+1,vec[i]);
    }

    printf("despues del ordenar : \n");
    ordenar(vec,ce);
   // miMap(vec,ce,sizeof(int),sumaUno);

    for(int i = 0; i < ce; i++){
        printf("%d. %d\n",i+1,vec[i]);
    }


   // char buffer[256];

    //leerArchivo();
    //crearAlumnos();

    //calcularPromedioArc();


    fclose(pf);
    return 0;

}
