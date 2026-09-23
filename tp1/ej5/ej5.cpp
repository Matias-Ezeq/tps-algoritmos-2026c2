#include <iostream>
using namespace std;

/*
    5) Leer la base y la altura de un rectángulo, calcular el perímetro y la superficie.
*/

int main()
{
    int base = 0, altura = 0;

    cout << "Ingrese la base del rectángulo (centímetros): ";
    cin >> base;
    cout << "Ingrese la altura del rectángulo (centímetros): ";
    cin >> altura;

    int perimetro = base*2 + altura*2;
    int superficie = base*altura;

    printf("Perímetro: %d\nSuperficie: %d\n",perimetro,superficie);

    return 0;
}