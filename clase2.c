#define ES_MINUSC(c) ( (c) >= 'a' && (c) <= 'z' ? 1 : 0 )
#define ES_MAYUSC(c) ( (c) >= 'A' && (c) <= 'Z') // por defecto luego de evaluar me retorna 1 si es verdadero o 0 si es falso
#define ES_LETRA(c) (ES_MAYUSC(c) || ES_MINUSC(c))
#define A_MINUSC(c) ((ES_MAYUSC(c)) ? ((c) + ('a' - 'A')) : (c))
#define FIL 10
#define COL 10
#include <stdio.h>

void mostrarVec( int *vec, int *ce){

    printf("VECTOR = {");
    for( int i = 0; i< *ce; i++){
        printf(" %d ",vec[i]);
    }
    printf("}; \n");
}


int insertPoss(int *vec, int num, int pos, int *ce){

    if( pos < 0 || pos > *ce) return -1;
    for(int i = *ce; i > pos; i--){
        vec[i] = vec[i-1];
    }
    vec[pos]= num;
    (*ce)++;

    return 0;
}

int insertOrd (int *vec, int num, int *ce){

    int i = *ce-1;
    while( i >= 0 && vec[i] > num ){
        vec[i+1] = vec[i];
        i--;
    }
    vec[i+1] = num;
    (*ce) ++;

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

//problema dos espacios ademas de saber que no modifico la cadena de caracteres, agregar los while que faltan para avanzar
//agregar la pregunta si es minuscula agregarle comparar con su opuesto
int esPalindromo(char *vec){

    char *pf = vec + cantPalabra(vec) - 1;
    char *pi = vec;
    while(pf - pi >= 0){
        while(!(ES_LETRA(*pi)) || !(ES_LETRA(*pf)) ){
            if(!ES_LETRA(*pi)) pi++;
            if(!ES_LETRA(*pf)) pf--;
        }
        if(A_MINUSC(*pf) != A_MINUSC(*pi))return -1;
        if(pf - pi == 0 && *pf == *pi) return 1;// condi para ser palindromo
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

void mostrarVecPos(char *ini, char *fin){

    printf(":::::::::::La palabra es::::::::::: \n\t");
    while(fin >= ini){
        printf("%c", *ini);
        ini++;
    }
    printf("\n::::::::::Fin palabra:::::::::::: \n");
}


char* proxPal(const char *vec, char **ini, char **fin){

    while(!ES_LETRA(*vec)){
        vec++;
    }
    *ini = vec;
    while(ES_LETRA(*vec)){
        vec ++;
    }
    *fin = vec;
    while(!ES_LETRA(*vec)){
        vec++;
    }

    return vec;

}

//MIS COPIAS DE FUNCIONES QUE SON DE STRING.H

int mStrlen(const char *vec){
    int aux = 0;
    while(*vec){
        vec++;
        aux++;
    }
    return aux;
}

char* mStrcpy(char* dest, const char *vec){
    char *ini = dest;

    while(*vec){
        *dest = *vec;
        vec++;
        dest++;
    }

    return ini;
}

char* mStrconcat(char *vec, const char *add){

    char* ini = vec;

    while(*vec){
        vec++;
    }
    while(*add){
        *vec = *add;
        vec++;
        add++;
    }

    return ini;
}

void imprimirMatriz(int mat[FIL][COL], int cFil, int cCol){

    for(int f = 0; f < cFil; f++){
        for(int c = 0; c < cCol ; c++){
            printf("%d -", mat[f][c]);
        }
        printf("\n");
    }



}
