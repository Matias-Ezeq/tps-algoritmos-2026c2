#include <iostream>
using namespace std;

/*
    Leer una serie de números reales, terminando la serie con un cero.
    Imprimir los datos a medida que se los ingresa junto con la suma parcial de los mismos.
*/

int main() {

    float in = 1, suma = 0;

    while (in != 0) {
        cout << "Ingrese número real: ";
        cin >> in;
        suma += in;
        printf("Número ingresado: %g\nSuma acumulada: %g\n",in,suma);
    }


    return 0;
}