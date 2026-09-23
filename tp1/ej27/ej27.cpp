#include <iostream>
using namespace std;

/*
    27) Hacer una función que indique si un número es primo o no.
*/

bool esPrimo(int numero) {
    bool primo = true;

    //horrible el approach pero en teoria sirve. Investigar si existe alguna fórmula menos "bruta"
    for (int i = numero-1; i > 1; i--){
        primo = primo && numero % i != 0;
    }

    return primo;
}

int main() {
    int numero;
    cin >> numero;
    cout << (esPrimo(numero) ? "primo": "no primo");

    return 0;
}