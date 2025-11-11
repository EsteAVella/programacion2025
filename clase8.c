#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char NyAp[30];
    float nota;
} tAlum;

typedef struct {
    int dni;
    char apellido[20];
    char nombre[30];
    float peso;
} tPersona;


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
    } while((op =! 4));
}

void* buscarElemento(void* list, void* element, size_t tam, int ce){

    char* pBus = list;
    char* pEle = element;
    int op;
    while(ce > 0){
        op = memcmp(pBus,pEle,tam);
        if(op == 0) return pBus;
        pBus+= tam;
        ce--;
    }
    return NULL;
}

int sumarNotas(int* list, int ce){
    int acum = 0;

    while(ce > 0){
        acum += *list;
        list++;
        ce--;
    }
    return acum;
}

void cambiarPunteros(int* a, int* b){
    int aux = 0;
    aux = *a;
    *a = *b;
    *b = aux;
}

void imprimirVecEntero(int* lista, int ce){

    printf("\n aca se imprime la lista\n { ");
    while(ce >0 ){
        printf(" %d ", *lista);
        lista++;
        ce--;
    }
    printf("}");

}

int cmpAscPersona(const void* a,const void *b){

    tPersona* p1 = (tPersona*)a;
    tPersona* p2 = (tPersona*)b;
    return (p2->dni- p1->dni);
}

void intercambioMem(void *ubi1, void *ubi2, size_t tam){

    char* aux = malloc(tam);
    char* p1 = ubi1;
    char* p2 = ubi2;

    memcpy(aux, p1, tam);
    memcpy(p1, p2, tam);
    memcpy(p2, aux, tam);

    free(aux);
}


int comparadorInt(void* a, void* b){

    int A = *(int*)a;
    int B = *(int*)b;

    if(A < B)return -1;
    if(A > B)return 1;
    return 0;
}

void ordenamientoGenerico(void* vec, int ce, size_t tam, int (*comparador)(void*, void*)) {

    char* base = (char*)vec;

    for (int i = 0; i < ce - 1; i++) {
        for (int j = 0; j < ce - i - 1; j++) {

            char* actual = base + j * tam;
            char* siguiente = base + (j + 1) * tam;

            if (comparador(actual, siguiente) > 0) {
                intercambioMem(actual, siguiente, tam);
            }
        }
    }
}

int abrirBin(){

    FILE *pf;
    pf = fopen("archivo.bin","rb");

    if(!pf){
        printf("no se abrio el archivo macho");
        return 0;
    }

    fclose(pf);
    return 1;
}
