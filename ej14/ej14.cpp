#include <iostream>
using namespace std;

/*
    14) Leer un número N y calcular su factorial.
*/

int main() {
    int numero, resultado = 1;
    cout << "Ingrese un número: ";
    cin >> numero;

    for (int i = numero; i > 0; i--){
        resultado = resultado * i;
    }

    printf("%d! = %d\n",numero,resultado);

    return 0;
}