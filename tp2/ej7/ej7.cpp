#include <iostream>
using namespace std;

public class NodoInt
{
int elemento;
NodoInt siguiente;
}

public class ListaInt
{
NodoInt primero;

public void separarContiguosDivisibles(){
    NodoInt nodoActual = primero;                                                                                       //1

    while (nodoActual -> siguiente != null)                                                                             //n
    {
        NodoInt nodoSiguiente = nodoActual -> siguiente;                                                                //1n
        if(nodoActual -> elemento % nodoSiguiente -> elemento == 0)                                                     //2n
        {
            nodoActual -> siguiente = new NodoInt(nodoactual -> elemento / nodoSiguiente -> elemento, nodoSiguiente);   //3n
        }
        nodoActual = nodoSiguiente;                                                                                     //1n
    }
}

// conplejidad: 10n+1

}

int main() {
    return 0;
}