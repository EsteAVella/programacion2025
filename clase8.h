#define REDOND(n)       ((int)((n) >= 0 ? (n) + 0.5 : (n) - 0.5 ))
#define ABSOLUTO(n)     ((n < 0) ? n*(-1) : n)
#define ENTERO(n)       ((int)(n))
#define DECIMAL(n)      (((n) >= 0) ? ((n) - (int)(n)) : (((n) - (int)(n))*-1))
#define ES_PAR(n)       (((n)%2) == 0 ? 1 : 0)
#define ES_DIGITO(c)    ((c) >= '0' && (c) <= '9')
#define A_MAYUSC(c)     ( ES_MINUSC(c) ? (c) - 32 : (c))
#define MAYOR(a, b)     ((a) > (b) ? (a) : (b) )

typedef struct {
    char NyAp[30];
    float nota;
}tAlum;

typedef struct{
    float prom;
    int total;
}Prom;



typedef struct {
    int dni;
    char apellido[20];
    char nombre[30];
    float peso;
} tPersona;


int aprobado(void *alum);

int filter(void *vec,int *ce, size_t tam,int (*filtro)(void *));

float minimoFloat(float*, int);

float promedioPar(float*, int);

void mostrarRevez(float*, int ce);

void archivoFloat(float*, int ce);

void menu(void);

void* buscarElemento(void* list, void* element, size_t tam, int ce);

int sumarNotas(int* list, int ce);

float calcularProm(int total, int ce);

void cambiarPunteros(int* a, int* b);

void imprimirVecEntero(int* lista, int ce);

int cmpAscPersona(const void* a,const void *b);

void intercambioMem(void*, void*, size_t);

int comparadorInt(void* a, void* b);

void ordenamientoGenerico(void* vec,int ce, size_t tam, int comparador(void*,void*));

int abrirBin();

