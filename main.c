#include "main.h"

int main()
{
    char cadena[] = "Nj qemh v ljs kraenkqbres; lj oqe qemh es oqevorme sgn ellhs --Istqt Asdmgj";
    char offset[] = "abcdghijkoqtuv";
    tAuto flota[]= {{"ford","focus",2018,18000.20},
                    {"toyota","corolla",2020,15000.20},
                    {"fiat","uno",1994,3500}
                };
    //Faltaria implementar el trio de funcions con eso practicar un poco mas
    map(&flota,aumentarPrecio,3);
    printf("%s \t \n\n", cadena);
    eDesencript(cadena,offset);
    printf("\n precio del auto %s es %.2f\n", flota[2].modelo, flota[2].precio);
    printf("%s \n\n", cadena);

    return 0;
}
