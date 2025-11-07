#include <stddef.h>

void* unionVectores2(void* vec1,int ce1, void* vec2, int ce2, size_t tam, int cmp(void*,void*)){

    void* aux = malloc((ce1+ ce2)*tam);
    void* ini = aux;
    int acc = 0;

    char* p1 = vec1;
    char* p2 = vec2;
    char* p3 = aux;

    while(ce1 > 0 && ce2 > 0){
        acc = cmp(p1,p2);
        if(acc == 0){
            memcpy(p3,p1, tam);
            p1; ce1--;
            p2++; ce2--;
            p3 += tam;
        } else if(acc > 0){
            memcpy(p3,p1,tam);
            p1 += tam;ce1--;
            aux += tam;
        } else {
            memcpy(p3,p2,tam);
            p2 += tam;ce2--;
            p3 += tam;
        }
    }
    return ini;
}

void* unionVectores(void* vec1,int ce1, void* vec2, int ce2, size_t tam, int cmp(void*,void*)){

    int tamAux = ce1 < ce2 ? ce1 : ce2;
    void* aux = malloc(tamAux * tam);
    void* ini = aux;
    int acc = 0;

    char* p1 = vec1;
    char* p2 = vec2;
    char* p3 = aux;
    int ce2ini = ce2;

    while(ce1 > 0){
        while( ce2 > 0){
            acc = cmp(p1,p2);
            if(acc == 0){
                memcpy(p3, p1, tam);
                p1 += tam; ce1--;
                p2 += tam;; ce2--;
                p3 += tam;
            }
            p2 += tam;;
            ce2--;
        }
        p2 = vec2;
        ce2 = ce2ini;
        p1+= tam;
        ce1--;
    }
    return ini;
}

int cmp(void* a, void* b){

    int valA = *(int*)a;
    int valB = *(int*)b;

    if(valA == valB) return 0;
    else if ( valA < valB ) return 1;
    else return -1;
}

//left join y rigth join; cmp y accion agregar cuando coincide un elemento del de la izquierda modificamos la misma firma pero con una accion en el medio, ver de usar la misma funcion para ambos casos
//funciones genericas, ver bien el tema, ver map filter y reduce para practicar genericos,


//ejercicio 5.13 unidad 5
typedef struct {
    int dni;
    int legajo;
    float promedio;
    int edad;
    char genero;
} tAlumno;
