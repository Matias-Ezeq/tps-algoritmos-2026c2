#include <iostream>
using namespace std;

/*
    9) Escribir un algoritmo que determine si un número M es divisible por N.
*/

int main(){
    int numero1,numero2 = 0;
    string resultado = "";

    cout << "ingrese dos números separados por un espacio: ";
    cin >> numero1 >> numero2;

    //c++ toma enteros positivos como verdadero y 0 como falso. módulo 2 retorna 0 si el numero es par y 1 si es impar
    if (numero1 % numero2){
        resultado = "no es divisible";
    }
    else {
        resultado = "es divisible";
    }

    printf("%d %s por %d\n",numero1,resultado.c_str(),numero2);

    return 0;
}