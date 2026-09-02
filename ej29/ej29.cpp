#include <iostream>
#include <vector>
using namespace std;

/*
    29) Desarrollar una función que devuelva en un vector los números primos entre 2 y 200. Reutilizar lo que ya se escribió y probó.
*/

// función del ej27
bool esPrimo(int numero) {
    bool primo = true;

    //horrible el approach pero en teoria sirve. Investigar si existe alguna fórmula menos "bruta"
    for (int i = numero-1; i > 1; i--){
        primo = primo && numero % i != 0;
    }

    return primo;
}

vector<int> primos2a200() {
    vector<int> primos = {};

    for (int i = 0; i <= 200; i++){
        if (esPrimo(i)){
            primos.push_back(i);
        }
    }

    return primos;
}



int main() {

    for (int primo : primos2a200()) {
        cout << primo << endl; 
    }

    return 0;
}