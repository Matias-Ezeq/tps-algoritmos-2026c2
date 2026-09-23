#include <iostream>
#include <vector>
using namespace std;

/*
    39) Escribir un algoritmo que construya un vector con los valores mínimos de cada una de las filas de una matriz.
*/

int minimoArray(int* array) {
    int minimo = array[0], largo = sizeof(array) / sizeof(array[0]);


    for(int i = 1; i < largo;i++){
        if (array[i] < minimo){
            minimo = array[i];
        }
    }

    return minimo;
}

vector<int> minimoFilas(int** matriz){
    vector<int> minimos = {};
    int largo = sizeof(matriz) / sizeof(matriz[0]);

    for (int i = 0; i < largo; i++){
        minimos.push_back(minimoArray(matriz[i]));
    }

    return minimos;
}



int main() {

    //código

    return 0;
}