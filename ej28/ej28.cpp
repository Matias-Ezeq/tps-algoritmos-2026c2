#include <iostream>
using namespace std;

/*
    28) Escribir una función que devuelva el máximo común divisor y el mínimo común múltiplo entre dos enteros.
    Nota: cuidado al modularizar (recordar que una función solo tiene que realizar una tarea).
*/

int mcd(int numero1, int numero2){
    int resultado = 0;

    //valor absoluto ya que los divisores no cambian entre un entero positivo y su negativo (-4 y 4 son divisibles por 2, y entre 2 y -2 es mayor 2).
    numero1 = abs(numero1);
    numero2 = abs(numero2);

    if (numero1 == 0){
        return numero2;
    }
    if (numero2 == 0){
        return numero1;
    }

    if (numero1 > numero2){
        resultado = mcd(numero2,numero1%numero2);
    }
    else {
        resultado = mcd(numero1,numero2%numero1);
    }
    
    
    return resultado;
}

int mcm(int numero1, int numero2){
    int resultado;
    
    //https://en.wikipedia.org/wiki/Least_common_multiple#Using_the_greatest_common_divisor

    //caso borde (división por 0)
    if (numero1 == 0 && numero2 == 0) {
        return 0;
    }

    //caso borde (mcm de dos negativos es igual al mcm de su valor absoluto)
    if (numero1 < 0 && numero2 < 0){
        numero1 = abs(numero1);
        numero2 = abs(numero2);
    }

    if (numero1 < numero2) {
        resultado = numero1 * (abs(numero2)/mcd(numero1,numero2));
    }
    else {
        resultado = numero2 * (abs(numero1)/mcd(numero1,numero2));
    }

    
    return resultado;
}

int main() {
    int a,b;
    cout << "enter two integers: ";
    cin >> a >> b;
    cout << "mcm of " << a << " and  " << b << ": " << mcm(a,b) << endl;

    return 0;
}