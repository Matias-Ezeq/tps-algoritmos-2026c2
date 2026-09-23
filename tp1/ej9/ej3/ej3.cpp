#include <iostream>
using namespace std;

/*
    3) Escribir un programa que lea el nombre de una persona y luego lo salude.
*/

int main()
{
    string nombre = "";
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);
    cout << "Hola " << nombre << "!" << endl;
    return 0;
}