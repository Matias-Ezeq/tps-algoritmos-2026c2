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
    int mcd = 1;

    
    return mcd;
}

int main() {
    int a,b;
    cout << "enter two integers: ";
    cin >> a >> b;
    cout << "mcd of " << a << " and  " << b << ": " << mcd(a,b);

    return 0;
}