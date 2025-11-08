#define ES_MINUSC(c) ( (c) >= 'a' && (c) <= 'z' ? 1 : 0 )
#define ES_MAYUSC(c) ( (c) >= 'A' && (c) <= 'Z') // por defecto luego de evaluar me retorna 1 si es verdadero o 0 si es falso
#define ES_LETRA(c) (ES_MAYUSC(c) || ES_MINUSC(c))
#include <string.h>
#include <stdlib.h>

char* proxPalabra(char *vec){

    while(!ES_LETRA(*vec)){
        vec++;
    }
    while(ES_LETRA(*vec)){
        vec++;
    }
    return vec;
}


int m_strcmp(char *vec, char *palabra){

    while(*palabra){

        if(*vec != *palabra){
            return 1;
        }

        vec++;
        palabra++;
    }
    //por si tiene una letra mas la palabra
    if(ES_LETRA(*vec)) return 1;
    return 0;
}

int contarPalbra (char *vec, char *palabra){

    int count = 0;
    while(*vec){

            if(!ES_LETRA(*vec)){
                vec++;
            }
            if(m_strcmp(vec, palabra)==0){
                count ++;
            }
            vec = proxPalabra(vec);
    }
    return count;
}

void normalizarVec(char *vec){

    if(!*vec) return exit(0);

    while(!ES_LETRA(*vec)){
        vec++;
    }
    while(*vec){
        while(!ES_LETRA(*vec)){
            vec++;
        }
        if(!ES_MAYUSC(*vec)){
            (*vec)-=32;
        }
        vec = proxPalabra(vec);
    }
}

int dentro(char a, char *offset){
    int calc = 0;

    while(*offset && a != *offset){
        offset ++;
        calc++;
    }
    if(*offset == a) return calc;

    return 0;
}

char cambio(char a, char* offset, int cant){
    int N = strlen(offset);
    int pos = dentro(a,offset);

    int nueva_pos = (pos + cant) % N;

    return offset[nueva_pos];
}

void eDesencript(char *vec, char *offset){
    int valor;
    int iter = 0;

    while(*vec){
        valor = dentro(*vec,offset);
        iter++;
        if(!ES_LETRA(*vec)) iter = 0;
        if(valor){
            *vec = cambio(*vec,offset,iter);
        }
        vec++;
    }
}


