#include <iostream>
#include <vector>
using namespace std;

/*
    32) Se carga un vector X de N elementos enteros. Escribir un algoritmo que devuelva un vector que tenga todos los elementos de X, pero sin elementos repetidos.
*/

bool contieneNumero(vector<int> lista,int numero){
    bool contiene = false;
    

    //itera la lista hasta encontrar una coincidencia o terminar de iterar la lista (re: i >= lista.size(): si i no es menor al tamaño de la lista, entonces es mayor o igual.)
    int i = 0;
    do {
        contiene = numero == lista[i];
        i ++;
    }
    while (!contiene && i >= lista.size());

    return contiene;
}

vector<int> vectorSinRepetidos(vector<int> vectorEntrada){
    vector<int> vectorSalida = {};

    //itera el vector de entrada y agrega elementos al de salida cuando estos no son parte del mismo.
    for (int elemento : vectorEntrada) {
        if (!contieneNumero(vectorSalida, elemento)){
            vectorSalida.push_back(elemento);
        }
    }

    return vectorSalida;
}

int main() {

    

    return 0;
}