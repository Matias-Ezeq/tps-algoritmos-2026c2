#include <iostream>
using namespace std;

/*
    21) Escribir un algoritmo que lea una serie de números reales y verifique si están ordenados en forma ascendente, descendente o si no están ordenados, informando por pantalla.
*/

int main() {
    long numero, numeroAnterior;

    char continuar = 's';
    enum {
        base,
        ascendente,
        descendente,
        desordenada
    }comparacion = base;
    string salida = "";

    cout << "Ingrese un número: ";
    cin >> numero;

    do {
        numeroAnterior = numero;
        cout << "Ingrese otro número: ";
        cin >> numero;
        
        switch (comparacion) {
            case base:
                if (numero >= numeroAnterior){
                    comparacion = ascendente;
                    salida = "ascendente";
                }
                if (numero <= numeroAnterior){
                    comparacion = descendente;
                    salida = "descendente";
                }
                break;
            case ascendente:
                if(numero < numeroAnterior){
                    comparacion = desordenada;
                    salida = "desordenada";
                }
                break;
            case descendente:
                if (numero > numeroAnterior){
                    comparacion = desordenada;
                    salida = "desordenada";
                }
                break;
            case desordenada:
                break;
        }
        numeroAnterior = numero;
        
        cout << "Hasta ahora, la lista es: " << salida << endl;
        

        cout << "Desea ingresar otro número? (s/n): ";
        cin >> continuar;
    }
    while (continuar != 'n' && continuar != 'N');

    return 0;
}