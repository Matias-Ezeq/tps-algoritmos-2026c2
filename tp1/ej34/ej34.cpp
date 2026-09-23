#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
    34) Si los números de un vector representan los coeficientes de un polinomio (de grado no mayor a 10), escribir un algoritmo que calcule la especialización de ese polinomio con un número que elige el usuario.
*/

double especializarPolinomio(vector<int> polinomio, float especializacion) {
    double resultado = 0;

    for (int i = 0; i < polinomio.size(); i++){
        resultado += polinomio[i] * pow(especializacion,i);
    }

    return resultado;
}

int main() {
    // 2^2 + 2^1 + 2^0 = 4 + 2 + 1 
    cout << especializarPolinomio({1,1,1},2);

    return 0;
}