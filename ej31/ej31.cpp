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

auto procesarNotas(vector<alumno> alumnos){
    
    //asumo un rango de notas "standard" como los de acá (nota entre 1 y 10, numero entero)
    
    int notasProcesadas[2][10] = {
        {1,2,3,4,5,6,7,8,9,10},
        {0,0,0,0,0,0,0,0,0,0}
    };

    //para cada alumno en el vector, lee su nota e incrementa el contador correspondiente, ya que indice = nota - 1 (ej: nota 10 -> columna 9)
    for (alumno alumno : alumnos){
        notasProcesadas[1][alumno.nota - 1] ++;
    }

    return notasProcesadas;
}

auto porcentajeNotas (int notas[2][10]){
    int totalNotas = 0;
    float porcentajes[10] = { 0 };

    //contamos el total de notas
    for (int cantidad : notas[1]){
        totalNotas += cantidad;
    }

    //aplicamos regla de 3 para calcular el porcentaje y lo almacenamos en su columna correspondiente
    for (int i = 0; i < 10; i++){
        porcentajes[i] = float(notas[1][i] * 100)/totalNotas;
    }

    return porcentajes;
}



int main() {

    //código

    return 0;
}