#include <iostream>
# include <vector>
using namespace std;

/*
    36) Escribir un algoritmo que halle un vector cuyos elementos son la suma de los elementos de cada fila de una matriz previamente ingresada.
*/

int sumarArray(int* array){
    int suma = 0, size = sizeof(array)/sizeof(array[0]);

    for (int i = 0; i < size; i++){
        suma += array[i];
    }

    return suma;
}

vector<int>sumaFilas(int** matriz){
    vector<int> sumas = {};
    int filas = sizeof(matriz) / sizeof(matriz[0]);

    for (int i = 0;i < filas; i++){
        sumas.push_back(sumarArray(matriz[i]));
    }

    return sumas;
}


int main() {

    //codigo

    return 0;
}