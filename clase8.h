typedef struct {
    char NyAp[30];
    float nota;
}tAlum;

int aprobado(void *alum);

int filter(void *vec,int *ce, size_t tam,int (*filtro)(void *));

float minimoFloat(float*, int);

float promedioPar(float*, int);

void mostrarRevez(float*, int ce);

void archivoFloat(float*, int ce);

void menu(void);
