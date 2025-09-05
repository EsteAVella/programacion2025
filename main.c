#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clase1.h"
#include "clase2.h"
#define TOL 0.5
#define EL 5
#define TAM 25

int main()
{
    int vec[TAM] = { 1,3,5 };
    char word[TAM] = {" AR ri ba la bi    rRa"};
    int ce = 3;

    int num = 5;
    //int pos = 1;

    mostrarVec(vec,&ce);
    printf("Vector modificado despues de la funcion \n");

    deleteNum(vec,num,&ce);
    mostrarVec(vec,&ce);

    printf("Cadena de caracteres sin modificar \n");
    printf("\t %s\n",word);

    printf("Cadena de caracteres modificada \n");
    printf("\t %s\n",word);
    printf("la cantidad de letras es %d \n",cantPalabra(word));

    int calc = esPalindromo(word);
    switch(calc){
    case -1:
        printf("no es palindromo la palabra %s \n", word);
        break;
    case 1:
        printf("Es palindromo la palabra %s \n", word);
        break;
    }

    printf("La palabra %s tiene el valor en entero de %d.\n",word, valorPalabra(word));

    char pal1[]={'h','o','l','a','\0'};
    char *pal2 = "hola";
    char pal3[] = {"hola"};

    printf("el valor de la primera cadena de caracteres %d\n",strlen(pal1));
    printf("el valor de la primera cadena de caracteres %d\n",strlen(pal2));
    printf("el valor de la primera cadena de caracteres %d\n",strlen(pal3));

    return 0;
}
