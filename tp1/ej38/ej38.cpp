#include <iostream>
using namespace std;

/*
    38) Escribir un algoritmo que determine si una matriz cuadrada ingresada es la matriz identidad. Optimizar el código.
*/

bool esIdentidad(int** matriz){
    int largo = sizeof(matriz) /sizeof(matriz[0]);
    bool esIdentidad = true;

    for (int i = 0;esIdentidad && i < largo; i++){
        for (int j = 0;esIdentidad && j < largo; j++){
            if (i == j){
                esIdentidad = matriz[i][j] == 1;
            }
            else {
                esIdentidad = matriz[i][j] == 0;
            }
        }
    }

    return esIdentidad;
}

int main() {

    //código

    return 0;
}