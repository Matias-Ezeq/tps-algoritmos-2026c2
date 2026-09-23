#include <iostream>
#include <string.h>
using namespace std;

/*
    6) Leer un número real y decir si es mayor, menor o igual a cero.
*/

int main() {
    double numero = 0;
    string resultado = "";

    cout << "Ingrese un número real: ";
    cin >> numero;

    if (numero > 0){
        resultado = "mayor";
    }
    else if (numero < 0){
        resultado = "menor";
    }
    else {
        resultado = "igual";
    }

    printf("%g es %s a 0\n",numero,resultado.c_str());
    //no se por qué es necesario castear resultado a 'char *' pero si no lo hago printf() muestra basura

    return 0;
}