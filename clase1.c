#include <math.h>

int factorial( int num ){

    int aux = 1;
    for(int i = num; i > 0; i--){
        aux *= i;
    }
    return aux;
}

float combinatoria(int m, int n){

    float calc = 0;
    if(!(m >= n && n >= 0)){
        return 0;
    }

    calc = (float)factorial(m)/(factorial(n)*factorial(m-n));

    return calc;

}

int potencia (int num, int exp){

    int aux = num;
    if (exp == 0){
        aux = 1;
        return aux;
    }

    for( int i = exp; i > 1 ; i--){
        aux *= num;
    }

    return aux;
}

float serieE( int exp, float tol){

    float aux = 1;
    int vuelta = 1;
    float calc = 1;
    while(1){
        aux = (float)potencia(exp,vuelta)/factorial(vuelta);
        calc += aux;
        vuelta ++;

        if( aux< tol)break;
    }

    return calc;
}

float raizCuadrada(int num, float tol){

    if(num == 0) return 0;

    float ant = num/2;
    float nuevo;

    while(1){
        nuevo = 0.5* (ant + num/ant);
            if(fabs(nuevo- ant) < tol){
                break;
            }
        ant = nuevo;
    }
    return nuevo;
}

int esFibonacci (int num){
    if( num < 1 ) return 0;

    int aux;
    int ant = 1;
    int act = 1;
    if(num == act) return 1;

    for(int i = 1; i <= num; i++){
        aux = ant + act;
            if(aux == num){
                return 1;
            }
        ant = act;
        act = aux;
    }
    return 0;
}

int clasificacion (int num){

    if( num < 1) return -1;
    int aux = 0;
    int calc;
    for( int i = num-1; i > 0; i--){
        if( num % i == 0 ){
            aux+= i;
        }
    }
    calc = num - aux;
    // Perfecto
    if( calc == 0) return 1;
   //deficiente
    if( calc > 0 ) return 0;
    //abundante
    if( calc < 0 ) return 2;
    return -1;
}

int productoSum (int a, int b){

    if( a == 0 || b == 0) return 0;
    int calc = 0;
    for(int i = b; i > 0; i--){
        calc+=a;
    }
    return calc;
}

int sumaPrimeros( int num ){

    if( num == 0 ) return 0;
    int calc = 0;

    for(int i = num; i > 0 ; i -- ){
        calc += i;
    }

    return calc;
}

int sumaPares( int num ){

    if( num == 0 ) return 0;
    int calc = 0;

    for(int i = num; i > 0 ; i -- ){
        if(i%2 == 0){
            calc += i;
        }
    }

    return calc;
}

int sumaNPares( int num ){

    int calc = 0;
    for( int i = 1; i <= num; i ++){
        calc+= i*2;
    }

    return calc;
}

int esPrimo(int num){
    int aux = 0;
    for( int i = num ; i > 0 ; i--){
        if( num % i == 0){
            aux++;
        }
    }
    if(aux == 2 ) return 1;
    return 0;
}
