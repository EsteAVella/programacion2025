#include "main.h"

int main()
{
    FILE *pf;
    tAlum alumnos[] = {
        {"Juan Perez", 7.5},
        {"Maria Gomez", 9.2},
        {"Luis Fernandez", 5.8},
        {"Ana Torres", 8.4},
        {"Carlos Ruiz", 4.9}
    };

    int ce = sizeof(alumnos) / sizeof(alumnos[0]);

    printf("Lista original:\n");
    for (int i = 0; i < ce; i++)
        printf("%-20s | %.1f\n", alumnos[i].NyAp, alumnos[i].nota);

    // Aplicar filtro
    filter(alumnos, &ce, sizeof(tAlum), aprobado);

    fopen("aprobados.txt","w");
    if(!pf)return -1;
    printf("\n Lista filtrada (solo aprobados):\n");
    for (int i = 0; i < ce; i++){
        printf("%-20s | %.1f\n", alumnos[i].NyAp, alumnos[i].nota);
        fwrite(alumnos[i],size_t tAlum,*ce,pf );
    }

    fclose(pf);
    return 0;
}
