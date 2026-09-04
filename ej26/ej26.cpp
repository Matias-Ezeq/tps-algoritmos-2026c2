#include <iostream>
#include <cmath>
using namespace std;

/*
    26) Hacer un programa principal en donde se pida al usuario ingresar los coeficientes de la cuadrática, e indicar si tiene o no raíces, y cuáles son en caso de tener, utilizando la función definida.
*/

struct raices{
    float raiz1;
    float raiz2;
};
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

raices calcularRaices(float a, float b, float c){
    raices raices;
    raices.raiz1 = calcularRaiz1(a,b,c);
    raices.raiz2 = calcularRaiz2(a,b,c);

    if (!isfinite(raices.raiz1)){
        raices.raiz1 = 0;
    }
    if (!isfinite(raices.raiz2)){
        raices.raiz2 = 0;
    }

    return raices;
}

int main() {

    float a = 0,b = 0,c = 0;
    raices raices;

    cout << "Ingrese los coeficientes de su polinomio: ";
    cin >> a >> b >> c;

    raices = calcularRaices(a,b,c);

    if (raices.raiz1 == 0 && raices.raiz2 == 0){
        cout << "el polinomio no tiene raices" << endl;
    }
    else {
        cout << "el polinomio tiene las siguientes raices: " << endl
            << "raiz 1: " << raices.raiz1 << endl
            << "raiz 2: " << raices.raiz2 << endl;
    }

    return 0;
}