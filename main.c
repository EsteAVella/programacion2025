#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clase1.h"
#include "clase2.h"
#include "clase5.h"
#define TOL 0.5
#define EL 5
#define TAM 25
#define FIL 10
#define COL 10

int main()
{
    int v[] = {5, 2, 9, 1, 7};
    int n = sizeof(v) / sizeof(v[0]);

    burbuja(v, n, des);

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");

    float vf[] = {5.2, 2.2, 9.1, 1.2, 7.3};
    n = sizeof(vf) / sizeof(vf[0]);

    burbujaFloat(vf,n, ascF);

    for (int i = 0; i < n; i++) {
        printf("%.1f ", vf[i]);
    }



    return 0;
}
