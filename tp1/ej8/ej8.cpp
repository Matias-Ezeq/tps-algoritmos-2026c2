#include <iostream>
using namespace std;

/*
    8) Escribir un algoritmo que determine si un número es par.
*/

int main(){
    int numero = 0;
    string resultado = "";

    cout << "ingrese un número: ";
    cin >> numero;

    //c++ toma enteros positivos como verdadero y 0 como falso. módulo 2 retorna 0 si el numero es par y 1 si es impar
    if (numero % 2){
        resultado = "impar";
    }
    else {
        resultado = "par";
    }

    printf("%d es %s\n",numero,resultado.c_str());

    return 0;
}