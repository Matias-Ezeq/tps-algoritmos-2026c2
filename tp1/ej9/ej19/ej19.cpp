#include <iostream>
using namespace std;

/*
    19) Dada una serie de números enteros terminada en cero, imprimir los tres mayores.
*/

int main() {
    long in = 0, maximo = 0, antemaximo = 0, antepemaximo = 0;


    do {
        cout << "Ingrese número real: ";
        cin >> in;
        switch (maximo + antemaximo + antepemaximo) {
            case 0 :
                maximo = antemaximo = antepemaximo = in;
                break;
            default:
                if(in > maximo) {
                    antepemaximo = antemaximo;
                    antemaximo = maximo;
                    maximo = in;
                }
                else if (in > antemaximo) {
                    antepemaximo = antemaximo;
                    antemaximo = in;
                }
                else if (in > antepemaximo) {
                    antepemaximo = in;
                }
        }
        cout    << "Top 3 valores máximos ingresados:" << endl 
                        << "1 - " << maximo << endl
                        << "2 - " << antemaximo << endl
                        << "3 - " << antepemaximo << endl;
    }
    while (in != 0);

    return 0;
}