#include <iostream>
#include <cmath>
using namespace std;

/*
    25) Hacer una función que devuelva las raíces reales de un polinomio de segundo grado y además indique si tiene o no raíces reales.
    Nota: utilizar la función realizada en el ejercicio 39. Si no tuviera raíces reales, devolverá 0 en ambas
*/

bool tieneRaices(float coeficiente1,float coeficiente2,float coeficiente3);
float calcularRaiz1(float a, float b, float c);
float calcularRaiz2(float a, float b, float c);

int main() {

    float a = 0,b = 0,c = 0;

    cout << "Ingrese los coeficientes de su polinomio: ";
    cin >> a >> b >> c;

    float raiz1 = calcularRaiz1(a,b,c), raiz2 = calcularRaiz2(a,b,c);

    if (tieneRaices(a,b,c)){
        //pueden ser ambas reales, o solo una, por eso verifico ambas igual. Si verifico solo la primera y es real, tengo que verificar la segunda también en caso de que no lo sea.
        cout    << "El polinomio tiene las siguientes raices: " << endl
                << "Raiz 1: " << ((isfinite(raiz1)) ? raiz1 : 0 ) << endl
                << "Raiz 2: " << ((isfinite(raiz2) && raiz2 != raiz1) ? raiz2 : 0 ) << endl;
    }
    else {
        cout << "el polinomio no tiene raices reales" << endl;
    }

    return 0;
}

float calcularRaiz1(float a, float b, float c) {
    float raiz = 0;

    raiz = (-b + sqrt( b*b - 4*a*c)) / (2*a);

    return (raiz);
}

float calcularRaiz2(float a, float b, float c) {
    float raiz = 0;

    raiz = (-b - sqrt( b*b - 4*a*c)) / (2*a);

    return (raiz);
}

bool tieneRaices(float a, float b, float c) {
    float raiz1 = 0, raiz2 = 0;

    // -b +/- raiz cuadrada(b^2 - 4*a*c) / 2*a

    raiz1 = calcularRaiz1(a,b,c);
    raiz2 = calcularRaiz2(a,b,c);

    return (isfinite(raiz1) || isfinite(raiz2));
}