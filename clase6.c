#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NAME "datos.txt"

typedef struct {
    char modelo[30];
    char marca[30];
    int anio;
    double precio;
} tAuto;

typedef struct {
    char nombre[20];
    int edad;
} tHumano;

typedef struct {
    char nombre[20];
    char apellido[20];
} tEstudiante;

void map(tAuto* flota, void accion(tAuto*veh),int ce){

    int i;
    for(i = 0; i < ce; i++){
        accion(flota);
        flota++;
    }
}

void escribirTexto(){

    FILE *pf;
    pf = fopen(NAME,"w");

    tHumano pers[] = {{"Juan",25}, {"Maria",31},{"Olga",99} };
    if(!pf){
        printf("cagamos no abrio personas.txt");
        return;
    }
    for(int i = 0; i < 3 ; i++){
        fprintf(pf,"%s %d\n", pers[i].nombre, pers[i].edad);
    }

    fclose(pf);
}

void leerArchivo() {
    FILE *pf = fopen(NAME, "r");
    tHumano per[3];
    int leidos = 0;

    if (!pf) {
        printf("Error al abrir '%s'\n", NAME);
        return;
    }

    // Lee hasta 3 personas o hasta que falle fscanf
    while (leidos < 3) {
        int r = fscanf(pf, "%29s %d", per[leidos].nombre, &per[leidos].edad);
        if (r != 2) {  // si no leyo 2 valores válidos, corta
            break;
        }
        leidos++;
    }

    fclose(pf);

    if (leidos == 0) {
        printf("No se pudo leer ningún registro válido.\n");
        return;
    }

    for (int i = 0; i < leidos; i++) {
        printf("Persona %d: %s tiene %d años\n", i + 1, per[i].nombre, per[i].edad);
    }
}

void crearAlumnos(){

    FILE *pf;
    pf = fopen("alumnos.txt","w");
    srand(time(NULL));
    if(!pf){
        return;
    }
    tEstudiante est[5] = {
        {"juan", "perez"},{"maria","gomez"},{"pedro","sosa"}};

    for(int i = 0; i < 3; i++){
        fprintf(pf,"%s %s", est[i].nombre, est[i].apellido);
        for(int j = 0; j < 6; j++){
            int nota = rand() % 5 + 6;
            fprintf(pf, " %d", nota);
        }
        fprintf(pf,"\n");
    }
    fclose(pf);

}

#include <stdio.h>

void calcularPromedioArc() {
    FILE *pf, *pfTemp;
    pf = fopen("alumnos.txt", "r");
    if (!pf) {
        printf("No se pudo abrir alumnos.txt\n");
        return;
    }

    pfTemp = fopen("alumnos_temp.txt", "w");
    if (!pfTemp) {
        fclose(pf);
        printf("No se pudo crear alumnos_temp.txt\n");
        return;
    }

    char nombre[20];
    char apellido[20];
    float notas[6];
    float promedio;
    char linea[256];

    fprintf(pfTemp, "%-15s %-15s", "NOMBRE", "APELLIDO");
    for (int i = 1; i <= 6; i++)
        fprintf(pfTemp, " %8s%d", "NOTA", i);
    fprintf(pfTemp, " %10s\n", "PROMEDIO");


    fprintf(pfTemp, "===================================================================================================================\n");

    while (fgets(linea, sizeof(linea), pf)) {
        int cant = sscanf(linea, "%s %s %f %f %f %f %f %f %f",
                          nombre, apellido,
                          &notas[0], &notas[1], &notas[2],
                          &notas[3], &notas[4], &notas[5],
                          &promedio);

        if (cant == 0)
            continue;

        // Si ya tiene promedio (9 valores)
        if (cant == 9) {
            fprintf(pfTemp, "%-15s %-15s", nombre, apellido);
            for (int i = 0; i < 6; i++)
                fprintf(pfTemp, " %8.2f", notas[i]);
            fprintf(pfTemp, " %10.2f\n", promedio);
            continue;
        }

        // Si tiene 8 valores (sin promedio)
        if (cant == 8) {
            promedio = 0;
            for (int i = 0; i < 6; i++)
                promedio += notas[i];
            promedio /= 6;

            fprintf(pfTemp, "%-15s %-15s", nombre, apellido);
            for (int i = 0; i < 6; i++)
                fprintf(pfTemp, " %8.2f", notas[i]);
            fprintf(pfTemp, " %10.2f\n", promedio);
        }
    }

    fclose(pf);
    fclose(pfTemp);
    remove("alumnos.txt");
    rename("alumnos_temp.txt", "alumnos.txt");
    printf("Archivo actualizado con formato mejorado.\n");
}
