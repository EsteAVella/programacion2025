#ifndef CLASE1_H
#define CLASE1_H

#include <math.h>
//recibimos un numero entero y calculamos su numero factorial
int factorial(int a);

//toma 2 numeros y muestra el factorial del primero / factorial del segundo * (primero - segundo) importante la validacion para no dividir por 0
float combinatoria(int m, int n);

//Se pasa por funcion una tolerancia y por sumas sucesivas se saca el numero e elevado a la algo
float serieE( int exp, float tol);

//para asistir a la funcion serieE
int potencia (int num, int exp);

float raizCuadrada(int num, float tol);

int esFibonacci (int num);

int clasificacion (int num);

int productoSum(int a, int b);

int sumaPrimeros( int num );

int sumaPares( int num);

int sumaNPares( int num );

int esPrimo( int num );
#endif

