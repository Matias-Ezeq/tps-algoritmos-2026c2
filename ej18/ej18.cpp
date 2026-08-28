#include <iostream>
using namespace std;

/*
    18) Leer A y B, enteros. Calcular C = A x B mediante sumas sucesivas e imprimir el resultado.
*/

int main() {
    int A = 0, B = 0, C = 0;

    cout << "ingrese el multiplicando (número entero): ";
    cin >> A;

    cout << "ingrese el multiplicador (número entero): ";
    cin >> B;

    for (int i = 0; i < A; i++){
        C += B;
    }

    cout << "Resultado de la multiplicación: " << C << endl;

    return 0;
}