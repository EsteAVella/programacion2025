#define ES_MINUSC(c) ( (c) >= 'a' && (c) <= 'z' ? 1 : 0 )
#define ES_MAYUSC(c) ( (c) >= 'A' && (c) <= 'Z') // por defecto luego de evaluar me retorna 1 si es verdadero o 0 si es falso
#define ES_LETRA(c) (ES_MAYUSC(c) || ES_MINUSC(c))
#define A_MINUSC(c) ((ES_MAYUSC(c)) ? ((c) + ('a' - 'A')) : (c))
#include <stdio.h>

void mostrarVec( int *vec, int *ce){

    printf("VECTOR = {");
    for( int i = 0; i< *ce; i++){
        printf(" %d ",vec[i]);
    }
    printf("}; \n");
}


int insertPoss(int *vec, int num, int pos,int *ce){

    if( pos < 0 || pos > *ce) return -1;
    for(int i = *ce; i > pos; i--){
        vec[i] = vec[i-1];
    }
    vec[pos]= num;
    (*ce)++;

    return 0;
}

int insertOrd ( int *vec, int num, int *ce){

    int i = *ce-1;
    while( i >= 0 && vec[i] > num ){
        vec[i+1] = vec[i];
        i--;
    }
    vec[i+1] = num;
    (*ce)++;

    return 0;
}

int elimPoss(int *vec, int poss, int *ce){

    int i = poss-1;

    while( i < *ce){
        vec[i] = vec[i+1];
        i++;
    }
    (*ce)--;

    return 0;
}

int deleteNum(int *vec, int num, int *ce){

    int i = 0;
    while( vec[i] != num && i <= *ce-1){
        i++;
    }
    if( i == *ce-1 && vec[i] != num ) return -1;
    while( i <= *ce){
        vec[i] = vec[i+1];
        i++;
    }
    (*ce)--;
    return 0;
}

int cantPalabra(char *vec){
    int cant = 0;

    while(*vec){
        cant ++;
        vec++;
    }
    return cant;
}


int esPalindromo(char *vec){

    char *pf = vec + cantPalabra(vec)-1;
    char *pi = vec;
    while(pf-pi >= 0){
        if(!ES_LETRA(*pi)) pi++;
        if(!ES_LETRA(*pf)) pf--;
        if(A_MINUSC(*pf) != A_MINUSC(*pi))return -1;
        if(pf-pi == 0 && *pf == *pi) return 1;
        if(A_MINUSC(*pf) == A_MINUSC(*pi)){
            pf--;
            pi++;
        }
    }

    return 0;
}

int valorPalabra(char *vec){

    int cant = 0;
    int i = 0;
    while(vec[i]){
        cant += (int)vec[i];
        i ++;
    }
    return cant;
}
