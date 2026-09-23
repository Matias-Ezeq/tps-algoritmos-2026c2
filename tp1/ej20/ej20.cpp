#include <iostream>
using namespace std;

/*
    20) Dada una serie de nombres con sus salarios respectivos, determinar el salario máximo, el mínimo y la persona que percibe cada uno
*/

int main()
{
    struct {
        string nombre;
        float salario;
    } empleado, mayor,menor; 

    mayor.nombre = menor.nombre = "";
    mayor.salario = menor.salario = 0;

    char continuar = 's';


    do {
        cout << "Ingrese nombre del empleado y su salario (nombre salario): ";
        cin >> empleado.nombre >> empleado.salario;

        switch (int(mayor.salario)){
            case 0:
                mayor.nombre = menor.nombre = empleado.nombre;
                mayor.salario = menor.salario = empleado.salario;
                break;
            default:
                if (empleado.salario > mayor.salario){
                    mayor.salario = empleado.salario;
                    mayor.nombre = empleado.nombre;
                }
                else if (empleado.salario < menor.salario) {
                    menor.salario = empleado.salario;
                    menor.nombre = empleado.nombre;
                }
                break;
        }
        cout    <<  "salario maximo: " << mayor.nombre << "( $" <<  mayor.salario << " )" << endl
                <<  "salario minimo: " << menor.nombre << "( $" <<  menor.salario << " )" << endl;

        cout    << "desea ingresar otro empleado? (s/n): ";
        cin >> continuar;
    }
    while (continuar != 'n' && continuar != 'N');

    return 0;
}
