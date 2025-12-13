#define TAM 30
typedef struct {
        char marca[TAM];
        char modelo[TAM];
        int anio;
        double precio;
} tAutos;


void aumentarPrecio(tAutos*veh);

void map(tAutos*flota,void accion(tAutos* veh), int ce);

void escribirTexto();

void leerArchivo();

void crearDatos();

void crearAlumnos();

void calcularPromedioArc();

void mostrarArchivo();

void printArchivo();

void miMap(void* datos, unsigned ce, size_t tam, void accion(void*));

int ordenarInt(void *a, void *b);

void sumaUno(void *a);

void duplicar(void *a);

void ordenar(int vec[], unsigned ce);
