#include <iostream>
using namespace std;

/*
    2) Leer dos números por teclado e imprimir:
        - La suma de ambos
        - La resta (el primero menos el segundo)
        - La multiplicación
        - La división
*/

int main()
{
    //inicialización de variables
    int numero1 = 0, numero2 = 0;

    cout << "Ingrese el primer número: ";
    cin >> numero1;

    cout << "Ingrese el segundo número: ";
    cin >> numero2;

    cout    << "Suma = " << numero1 + numero2 << endl
            << "Resta = " << numero1 - numero2 << endl
            << "Multiplicación = " << numero1*numero2 << endl
            << "División = " << float(numero1)/numero2 << endl;
            
    return 0;
}