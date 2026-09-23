#include <iostream>
using namespace std;

/*
    10) Leer dos números y luego una opción que puede ser:
        “ + ”: suma
        “ – “: resta
        “ * ”: multiplicación
        “ / “: división
    Según la opción elegida realizar el cálculo.
*/

int main(){
    float numero1 = 0,numero2 = 0;
    char operando = ' ';
    float resultado = 0;

    cout << "ingrese dos números separados por un espacio: ";
    cin >> numero1 >> numero2;
    cout << "ingrese la operación que desea realizar (+,-,*,/): ";
    cin >> operando;

    switch (operando) {
        case '+':
            resultado = numero1 + numero2;
            break;
        case '-':
            resultado = numero1 - numero2;
            break;
        case '*':
            resultado = numero1 * numero2;
            break;
        case '/':
            resultado = numero1 / numero2;
            break;
        default:
            cout << "Operación inválida\n";
            return 1;
    }

    printf("%g %c %g = %g\n",numero1,operando,numero2,resultado);
    return 0;
}