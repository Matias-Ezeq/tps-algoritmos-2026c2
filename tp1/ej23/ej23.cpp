#include <iostream>
using namespace std;

/*
    23) Leer N y luego N lotes de números reales que terminan con un valor 0, y calcular la media individual de cada lote, junto con la media total de todos los números ingresados.
*/

/*
    cantidad = N
    suma lotes[N] = {}
    iteraciones lote actual
    promedio lotes[N] = {}

    suma general = suma de elementos de suma lotes
    promedio general = promedio de elementos de sumaLotes

    lote 1: 4,
    lote 2: 
    ...
    lote N:


*/

int main() {
    int lotes = 0, numero = 1, iteracionActual = 0, total = 0, iteracionesTotales = 0;

    cout << "Ingrese cantidad de lotes: ";
    cin >> lotes;

    int totalesAcumulados[lotes] = { };
    int mediaLotes[lotes] = { };

    for (int i = 0; i < lotes; i++) {
        numero = 1;
        iteracionActual = 0;
        while (numero != 0) {
            cout << "Ingrese un número (lote " << i+1 << "/" << lotes << "): ";
            cin >> numero;
            totalesAcumulados[i] += numero;
            mediaLotes[i] = totalesAcumulados[i] / (iteracionActual + 1);
            cout << "media del lote actual: " << mediaLotes[i] << endl;
            iteracionActual += 1;
            iteracionesTotales += 1;
        }
    }

    for (int i = 0; i < lotes; i++){
        cout << "Lote: " << i + 1 << ", media: " << mediaLotes[i] << endl;
        total += totalesAcumulados[i];
    }

    cout << "media total: " << total / iteracionesTotales << endl;
    

    return 0;
}