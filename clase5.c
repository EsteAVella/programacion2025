#include <stddef.h>
#include <stdlib.h>
char* encriptarChar(int TAM, int offset, char* tipo, char* vec){

    char* pi = malloc(TAM+1);
    if(!pi) return NULL;
    char* ini = pi;
    while(*vec){
        *pi += *vec + offset;

        vec++;
        pi++;
    }
    return ini;
}

void* encriptar( size_t,int offset, char* tipo, char* vec){

    char* pi = malloc(12+1);
    if(!pi) return NULL;
    char* ini = pi;
    while(*vec){
        *pi += *vec + offset;
        vec++;
        pi++;
    }

    return ini;

}

void burbuja(int arr[], int ce, int order(int, int)) {
    for (int i = 0; i < ce - 1; i++) {
        for (int j = 0; j < ce - i - 1; j++) {
            if (order(arr[j], arr[j + 1]) > 0) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}


int asc(int a, int b) {
        if (a > b) return 1;
        if (a < b) return -1;
    return 0;
}


int des(int a, int b) {
        if (a > b) return -1;
        if (a < b) return 1;
    return 0;
}

void burbujaFloat(int arr[], int ce, int order(float, float)) {
    for (int i = 0; i < ce - 1; i++) {
        for (int j = 0; j < ce - i - 1; j++) {
            if (order(arr[j], arr[j + 1]) > 0) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int ascF(float a, float b) {
        if (a > b) return 1;
        if (a < b) return -1;
    return 0;
}


int desF(float a, float b) {
        if (a > b) return -1;
        if (a < b) return 1;
    return 0;
}

