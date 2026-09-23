#include <iostream>
using namespace std;

/*
    37) Escribir un programa que calcule la traza de una matriz cuadrada. Recordar que la traza de una matriz es la suma de los elementos de su diagonal principal.
*/

float calcularTraza(int** matriz) {
    int largo = (sizeof(matriz) / sizeof(matriz[0]));
    float traza = 0;

    for (int i = 0; i < largo; i++){
        traza += matriz[i][i];
    }
 
    return traza;
}


int main() {

    //código

    return 0;
}