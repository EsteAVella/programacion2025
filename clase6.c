typedef struct {
    char modelo[30];
    char marca[30];
    int anio;
    double precio;
} tAuto;

void aumentarPrecio(tAuto*veh){

    veh->precio = veh->precio*1,10;
}


void map(tAuto* flota, void accion(tAuto*veh),int ce){

    int i;
    for(i = 0; i < ce; i++){
        accion(flota);
        flota++;
    }
}
