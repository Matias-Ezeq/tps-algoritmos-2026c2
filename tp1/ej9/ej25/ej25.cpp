#include <iostream>
#include <cmath>
using namespace std;

/*
    25) Hacer una función que devuelva las raíces reales de un polinomio de segundo grado y además indique si tiene o no raíces reales.
    Nota: utilizar la función realizada en el ejercicio 39. Si no tuviera raíces reales, devolverá 0 en ambas
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