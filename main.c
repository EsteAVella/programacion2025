#include <stdio.h>
#define MAXLINE 100
#include "repaso.h"
#include "main.h"

int main()
{
    int list[10] = {6, 6, 7, 7, 9, 9};
    int ce = 6;
    Prom tprom[2];
    int* pI = list;
    int* pD = list+2;
    tPersona personas[] = {
        {40200123, "Gomez", "Laura", 65.5},
        {40111222, "Perez", "Juan", 80.0},
        {40555444, "Lopez", "Ana", 55.0}
    };
    int tamArreglo = sizeof(personas)/sizeof(tPersona);
/*
    int ce = 6;
    int elemento = 1;
    void* pList = list;
    float result = minimoFloat(list,ce);

    printf("el numero mas chico es %f\n", result);

    result = promedioPar(list,ce);
    printf("el promedio de los pares es %f\n", result);

    mostrarRevez(list,ce);
    archivoFloat(list,ce);
    menu();
    void* result = buscarElemento(pList,&elemento,sizeof(int),ce);
    printf("se habra encontrado la direccion de memoria? %p\n: ", result);
*/
    int cant = sumarNotas(list,ce);
    tprom[0].total = cant;
    tprom[0].prom = (float)cant/ce;

    printf("PROMEDIO ::: %d\n",tprom[0].total);
    printf("REDONDEAR :: %d\n",REDOND(1.4));
    printf("ENTERO :: %d\n",ENTERO(2.8));
    printf("DECIMAL:: %f\n",DECIMAL(2.8));
    printf("ABSOLUTO :: %d\n",ABSOLUTO(-99));
    printf("ES PAR :: %d\n",ES_PAR(2));
    printf("A MAYUSC :: %c",A_MAYUSC('c'));
    printf("MAYOR___ %d ____ \n", MAYOR(3,5));
    imprimirVecEntero(list,ce);
    cambiarPunteros(pI,pD);
    imprimirVecEntero(list,ce);
    qsort(personas,tamArreglo, sizeof(tPersona),cmpAscPersona);

    return 0;
}
