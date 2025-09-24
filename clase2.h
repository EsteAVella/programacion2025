#define ES_MINUSC(c) ( (c) >= 'a' && (c) <= 'z' ? 1 : 0 )
#define ES_MAYUSC(c) ( (c) >= 'A' && (c) <= 'Z') // por defecto luego de evaluar me retorna 1 si es verdadero o 0 si es falso
#define ES_LETRA(c) (ES_MAYUSC(c) || ES_MINUSC(c))
#define A_MINUSC(c) ((ES_MAYUSC(c)) ? ((c) + ('a' - 'A')) : (c))
#define FIL 10
#define COL 10
#include <stdio.h>

//Mostrar vector de ints;

void mostrarVec(int *vec,int *ce);

//Array unidireccionales

int insertPoss (int*vec, int num, int pos,int *ce);

int insertOrd (int *vec, int num, int *ce);

int elimPoss(int *vec, int pos, int *ce);

int deleteNum(int *vec, int num, int *ce);

int esPalindromo(char *vec);

int cantPalabra(char *vec);

int valorPalabra(char *vec);

void invertirVec(char *vec);
//para cuando tengo un vector en la ultima posicion le agrego uno y busco la proxima palabra
char* proxPal(char *vec, char **ini, char **fin);

void mostrarVecPos(char *ini, char *fin);

//MIS COPIAS DE FUNCIONES QUE SON DE STRING.H
int mStrlen(const char *vec);

char* mStrcpy(char* dest, const char *vec);

char* mStrconcat(char *vec, const char *add);

void imprimirMatriz(int mat[FIL][COL], int cfilas, int cCol);
