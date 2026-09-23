#include <iostream>
#include <cmath>
using namespace std;

/*
    24) Hacer una función que, dado los coeficientes de un polinomio de segundo grado (3 números reales), indique si tiene o no raíces reales, devolviendo un valor booleano.
*/

bool tieneRaices(float coeficiente1,float coeficiente2,float coeficiente3);

int main() {
    float a,b,c;

    cout << "ingrese los coeficientes de su polinomio: ";
    cin >> a >> b >> c;

    if (tieneRaices(a,b,c)){
        cout << "tiene solución Real" << endl;
    }
    else {
        cout << "no tiene solución real" << endl;
    }

    return 0;
}

bool tieneRaices(float a, float b, float c) {
    float raiz1 = 0, raiz2 = 0;

    // -b +/- raiz cuadrada(b^2 - 4*a*c) / 2*a

    raiz1 = (-b + sqrt( b*b - 4*a*c)) / (2*a);
    raiz2 = (-b - sqrt( b*b - 4*a*c)) / (2*a);

    return (isfinite(raiz1) || isfinite(raiz2));
}