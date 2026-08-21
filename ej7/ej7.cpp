#include <iostream>
using namespace std;

/*
    7) Leer dos números reales e imprimir el mayor de ellos.
*/

int main(){
    float numero1, numero2 = 0;

    cout << "ingrese dos números separados por un espacio: ";
    cin >> numero1 >> numero2;

    if (numero1 >= numero2){
        cout << numero1 << "\n";
    }
    else {
        cout << numero2 << "\n";
    }


    return 0;
}