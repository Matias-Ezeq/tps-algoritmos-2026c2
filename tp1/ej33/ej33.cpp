#include <iostream>
#include <vector>
using namespace std;

/*
    33) Se leen dos vectores A y B, de N y M elementos respectivamente. Construir un
    algoritmo que halle los vectores unión e intersección de A y B. Previamente habrá
    que ordenarlos
*/

//ej 32
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


vector<int> ordenarVector(vector<int> vectorAOrdenar){
    vector<int> vectorSalida = {};
    int minimo = vectorAOrdenar.at(0), indiceMinimo=0;

    while (vectorAOrdenar.size() > 0){
        for (int i = 1; i < vectorAOrdenar.size() -1; i++){
            if (minimo > vectorAOrdenar.at(i)){
                minimo = vectorAOrdenar.at(i);
                indiceMinimo = i;
            }
        }
        vectorSalida.push_back(minimo);
        minimo = vectorAOrdenar.at(0);
        vectorAOrdenar.erase(vectorAOrdenar.begin() + indiceMinimo);
    }
}

vector<int> hallarUnion(vector<int> vectorA, vector<int> vectorB) {
    vector<int> vectorSalida = {};

    for (int numero : vectorA){
        vectorSalida.push_back(numero);
    }
    for (int numero : vectorB){
        vectorSalida.push_back(numero);
    }

    return ordenarVector(vectorSinRepetidos(vectorSalida));
}

vector<int> hallarInterseccion(vector<int> vectorA, vector<int> vectorB) {
    vector<int> vectorSalida = {};
    vectorA = ordenarVector(vectorA);
    vectorB = ordenarVector(vectorB);
    
}

int main() {

    //código

    return 0;
}