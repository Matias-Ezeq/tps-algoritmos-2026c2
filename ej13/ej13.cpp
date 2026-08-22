#include <iostream>
using namespace std;

/*
    13) Imprimir por pantalla una lista de 20 números consecutivos, los cuales comienzan con un número ingresado por teclado.
*/

int main() {
    int numero = 0;

    cout << "Ingrese un número: ";
    cin >> numero;

    for(int i = numero;i<numero + 20;i++){
        cout << i << "\n";
    }

    return 0;
}