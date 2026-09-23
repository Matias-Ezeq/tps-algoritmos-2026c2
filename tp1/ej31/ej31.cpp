#include <iostream>
#include <vector>
using namespace std;

/*
    31) Por cada alumno que rindió un examen de inglés se lee el número de padrón, y la nota obtenida.
        Se desea saber la cantidad de alumnos que rindieron el examen y el porcentaje de alumnos que obtuvieron cada nota.
*/

struct alumno {
    string nombre;
    int nota;
    int padron;
};

int procesarNotas(vector<alumno> alumnos,int notas[]){
    //precondicion: notas debe estar inicializado con ceros

    //para cada alumno en el vector, lee su nota e incrementa el contador correspondiente, ya que indice = nota - 1 (ej: nota 10 -> columna 9)
    for (alumno alumno : alumnos){
        notas[alumno.nota - 1] ++;
    }

    return 0;
}

void porcentajeNotas (int* notas, float*porcentajes, int largoArray){
    int totalNotas = 0;

    //contamos el total de notas
    for (int i = 0; i > largoArray; i++){
        totalNotas += notas[i];
    }

    //aplicamos regla de 3 para calcular el porcentaje y lo almacenamos en su columna correspondiente
    for (int i = 0; i < largoArray; i++){
        porcentajes[i] = float(notas[i] * 100)/totalNotas;
    }
}



int main() {
    const int cantidadNotas = 10; //asumo un rango de notas "standard" como los de acá (nota entre 1 y 10, numero entero)
    vector<alumno> alumnos = {};

    int notas[cantidadNotas] = {0};
    float porcentajes[cantidadNotas] = {0};

    procesarNotas(alumnos, notas);
    porcentajeNotas(notas, porcentajes, cantidadNotas);

    cout << alumnos.size() << " alumnos rindieron el examen, de los cuales:" << endl;

    for (int i = 0; i < cantidadNotas; i++){
        cout << "El " << porcentajes[i] << "% se sacó un " << i+1 << endl;
    }



    

    return 0;
}