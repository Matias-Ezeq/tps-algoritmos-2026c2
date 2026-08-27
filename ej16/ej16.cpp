#include <iostream>
using namespace std;

/*
    Dada una serie de números reales, determinar el valor máximo, el mínimo, y las posiciones en que estos se encontraban en la serie.
    El programa deberá ir preguntando si hay más números para ingresar.
*/

int main() {
    
    int valor=0,ciclo=0,mayor=0,menor=0,posMayor=0,posMenor = 0;
    char seguir = 's';

        do {
            cout << "Ingrese un número: ";
            cin >> valor;

            switch (ciclo){
                case 0:
                    menor = valor;
                    mayor = valor;
                    posMenor = ciclo;
                    posMayor = ciclo;
                    break;
                default:
                    if(valor < menor){
                        menor = valor;
                        posMenor = ciclo;
                    }
                    if(valor>mayor){
                        mayor=valor;
                        posMayor=ciclo;
                    }
                    break;
            }
            ciclo ++;

            cout    << "Mayor: " << mayor << ", posición: " << posMayor <<endl
                    << "Menor: " << menor << ", posición: " << posMenor <<endl;

            cout << "continuar? (s/n)" << endl;
            cin >> seguir;

        }
        while (seguir != 'n' && seguir != 'N');

    return 0;
}