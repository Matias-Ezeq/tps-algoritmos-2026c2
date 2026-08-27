#include <iostream>
using namespace std;

/*
    Leer un valor N y luego N números enteros. Se pide imprimir el mayor y el menor y las veces que aparece cada uno
*/

int main() {
    int largo=0,maximo=0,minimo=0,cantidadMaximo=0,cantidadMinimo=0;

    cout << "Ingrese la cantidad de números a comparar: ";
    cin >> largo;

    int lista[largo];

    //populamos la lista
    for (int i = 0; i<largo;i++){
        cout << "ingrese un número (" << i+1 << "/" << largo << "): ";
        cin >> lista[i];
    }

    //buscamos los valores maximos y mínimos y su n° de apariciones
    
    for (int i = 0; i < largo; i++){
        switch (i) {
        case 0:
            minimo = maximo = lista[i];
            cantidadMinimo = 1;
            cantidadMaximo = 1;
            break;
        default:
            if (lista[i] < minimo){
                minimo = lista[i];
                cantidadMinimo = 1;
            }
            else if (lista[i] == minimo){
                cantidadMinimo ++;
            }

            if (lista[i] > maximo){
                maximo = lista[i];
                cantidadMaximo = 1;
            }
            else if (lista[i] == maximo){
                cantidadMaximo ++;
            }
            break;
        }
    }

    cout    << "Valor mínimo: " << minimo << " (" << cantidadMinimo << ")" << endl
            << "Valor máximo: " << maximo << " (" << cantidadMaximo << ")" << endl;

    return 0;

}