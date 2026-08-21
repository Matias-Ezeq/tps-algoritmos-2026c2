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
    int numero1, numero2 = 0;

    cout << "Ingrese el primer número: ";
    cin >> numero1;

    cout << "Ingrese el segundo número: ";
    cin >> numero2;

    printf("Suma = %d \nResta = %d \nMultiplicación = %d\nDivisión = %g\n",numero1 + numero2,numero1 - numero2,numero1*numero2,float(numero1)/numero2);
    return 0;
}