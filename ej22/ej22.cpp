#include <iostream>
using namespace std;

/*
    La relación entre temperaturas Celsius y Fahrenheit está dada por: C = 5/9 * (F – 32).
    Escribir un algoritmo que haga una tabla de valores Celsius-Fahrenheit, para valores entre OºF y 200ºF, a intervalos de 10º.
*/

int main() {
    float celsius = 0;
    
    for (int i = 0; i <= 200; i += 10){
        celsius = 5.0 / 9 * float(i - 32);
        
        cout << i << "°F"<< " = " << celsius << "°C" << endl; 

    }


    return 0;
}

