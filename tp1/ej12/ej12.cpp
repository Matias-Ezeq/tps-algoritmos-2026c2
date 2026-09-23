#include <iostream>
using namespace std;

/*
    12) Pasar un período expresado en segundos a un período expresado en días, horas, minutos y segundos.
*/

int main() {
    int dias = 0,horas = 0,minutos = 0,segundos = 0;

    cout << "Ingrese número de segundos: ";
    cin >> segundos;

    //obtenemos los valores de cada campo
    minutos = segundos / 60;
    horas = minutos / 60;
    dias = horas / 24;

    //pasamos los campos correspondientes a su valor de "resto" de la división del paso anterior
    segundos = segundos % 60;
    minutos = minutos % 60;
    horas = horas % 24;


    printf("%d:%d:%d:%d ",dias,horas,minutos,segundos);
    printf("(%d dias, %d horas, %d minutos, y %d segundos)\n",dias,horas,minutos,segundos);

    return 0;
}