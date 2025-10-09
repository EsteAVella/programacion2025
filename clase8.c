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
