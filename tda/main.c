#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int cc;
    int cf;
    size_t tamElementB;
    void* mat;
    } matDinamica;

int main()
{
    char pal[10] = "hola";
    printf("%d", strlenr(pal));
    return 0;
}
/*
void* recorrerMatPrin(matDinamica* m, void* accion(void*)){
    void* paux;
    int tam;

    if(cc>cf){
        tam = cf;
    }else {
        tam = cc;
    }
    for(int i = 0; i < tam; i++ ){
        pAux = m->mat + (i*m->cc+i)*m->tamElementB;
        accion(pAux);
    }


}

size_t tamanio (matDinamica* m){
    return (*size_t)m->cc * m->cf * m->tamElementB;
}
void* calcularTrans(matDinamica* m){


}

*/

int strlenr(char* pal){
    if(*pal == '\0'){
        return 0;
    }
    return strlenr(pal+1)+1;
}
