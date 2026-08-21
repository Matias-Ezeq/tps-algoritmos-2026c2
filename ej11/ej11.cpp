#include <iostream>
using namespace std;

/*
    11) Formar un menú de 4 opciones y, al elegir una de ellas, saldrá un cartel diciendo   qué opción se eligió o si fue una opción incorrecta.
*/

int main() {
    char opcion = ' ';
    string texto = "";
    cout << "1 - No hacer nada\n2 - Tampoco hacer nada\3 - Hacer algo (nada)\n4 - Terminar ejecución\nElija una opción (1,2,3,4): ";
    cin >> opcion;

    switch (opcion) {
        case '1':
            texto = "No hacer nada";
            break;
        case '2':
            texto = "Tampoco hacer nada";
            break;
        case '3':
            texto = "Hacer algo (nada)";
            break;
        case '4':
            texto = "Terminar ejecución";
            break;
        default:
            cout << "Opción inválida.\n";
            return 1;
    }

    printf("Usted eligió la opción %c : \"%s\".\n",opcion,texto.c_str());

    return 0;
}