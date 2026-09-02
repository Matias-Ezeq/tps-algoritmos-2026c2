#include <iostream>
#include <vector>
using namespace std;

/*
    30) Dados dos vectores A y B, de N elementos cada uno, se desean calcular:
        a. El vector suma.
        b. El producto escalar.
*/

vector<float> vectorSuma(vector<float> vector1, vector<float> vector2){
    //precondición: ambos vectores deben ser del mismo tamaño
    vector<float> resultado = {};

    for (int i = 0; i < vector1.size(); i++) {
        resultado.push_back(vector1[i] + vector2[i]);
    }

    return resultado;
}

float productoEscalar(vector<float> vector1, vector<float> vector2){
    //precondición: ambos vectores deben ser del mismo tamaño
    float resultado = 0;

    for (int i = 0; i < vector1.size(); i++) {
        resultado += vector1[i]*vector2[i];
    }

    return resultado;
}


int main() {

    vector<float> vector1 = {1,2,3}, vector2 = {4,5,6};

    for (float elemento : vectorSuma(vector1,vector2)){
        cout << elemento << " ";
    }
    cout << endl;

    cout << productoEscalar(vector1,vector2) << endl;

    return 0;
}