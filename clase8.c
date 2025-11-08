#include <stddef.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    char NyAp[30];
    float nota;
} tAlum;

int aprobado(void *alum) {
    tAlum *a = (tAlum *) alum;
    return a->nota >= 4.0;
}

void filter(void *vec, int *ce, size_t tamB, int (*filtro)(void *)) {
    char *pl = (char *)vec;
    char *pe = (char *)vec;

    for (int i = 0; i < *ce; i++) {
        if (filtro(pl)) {
            if (pe != pl) {
                memcpy(pe, pl, tamB);
            }
            pe += tamB;
        }
        pl += tamB;  // mover siempre el puntero de lectura
    }

    // actualizar cantidad de elementos válidos
    *ce = (int)((pe - (char *)vec) / tamB);
}

float minimoFloat(float list[],int ce){

    float num = *list;
    while(ce > 0){
        if(*list < num){
            num = *list;
        }
        list++;
        ce--;
    }
    return num;
}

float promedioPar(float list[], int ce){

    float acum = 0;
    int ceAux = ce;
    int cant = 0;

    while(ceAux > 0){
        acum += *list;
        list += 2;
        ceAux-=2;
        cant++;
    }

    return acum/cant;
}

void mostrarRevez(float list[], int ce){

    list += ce-1;

    if(ce == 0){
        return;
    }

    printf("El array al revez es === \n {");

    while(ce > 0){
        printf(" %f ",*list);
        list--;
        ce--;
    }
    printf("}");
}

void archivoFloat(float list[], int ce){

    FILE *pf;
    char nombre[] = "float.txt";
    pf = fopen(nombre,"w");
    if(!pf){
        printf("fallo creacion de archivo");
        return;
    }
    while(ce > 0){
        fprintf(pf, "%.2f\n", *list);
        list++;
        ce--;
    }
    fclose(pf);

    printf("Archivo creado %s creado correctamente",nombre);
}

void menu(){
    int ce = 0;
    float list[10];
    int op;
    float result;

    printf("ingrese la cantidad de numero que va a ingresar \n");
    scanf("%d",&ce);

    for( int i = 0; i < ce; i++){
        printf("ingrese el %d numero \n ",i+1);
        scanf("%f",&list[i]);
    }

    do{
        printf("1-buscar minimo elemento\n");
        printf("2-promedio pares\n");
        printf("3-mostrar inverso\n");
        printf("4-salir\n");
        printf("Ingrese la opcion");
        scanf("%d",&op);

        switch(op){
            case 1:
                result = minimoFloat(list,ce);
                printf("el resultado es %f",result);
                break;
            case 2:
                result = promedioPar(list,ce);
                printf("el resultado del promedio es %f",result);
                break;
            case 3:
                mostrarRevez(list,ce);
                break;
            case 4:
                break;
            }
        } while(op =! 4);
}

