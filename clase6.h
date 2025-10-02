#define TAM 30
typedef struct {
        char marca[TAM];
        char modelo[TAM];
        int anio;
        double precio;
} tAuto;


void aumentarPrecio(tAuto*veh);

void map(tAuto*flota,void accion(tAuto* veh), int ce);
