#include <iostream>
#include <cmath>
using namespace std;

/*
    4) Dado el radio R de una esfera que se solicita por teclado, calcular e imprimir su superficie y su volumen.
*/

int main()
{
    float radio;
    cout << "Ingrese radio de la esfera (centímetros): ";
    cin >> radio;
    /*
        volumen = (4/3)*pi*r³
        superficie = 4*pi*r²
    */
    double volumen = (4.0/3)*M_PI*pow(radio,3);
    double superficie = 4*M_PI*pow(radio,2);

    printf("Volumen: %g cm³\nSuperficie: %gcm²\n",volumen,superficie);
    return 0;
}