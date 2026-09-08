#include <iostream>
#include <vector>
using namespace std;

/*
    42) Definir un vector Gondola en donde puedan almacenar datos de a lo sumo 50 productos del supermercado. Cada producto se define por su nombre, código de barras, precio y un indicador si está en oferta o no (si estuviera en oferta al precio se le debe descontar un 10%).
    La aplicación debe permitir mediante un menú de opciones:
        a. Cargar productos en el vector.
        b. Buscar un producto indicando su nombre.
        c. Buscar un producto por código de barra.
        d. Poder modificar el precio de algún producto.
        e. Quitar un producto que esté en el vector.
        f. Indicar la cantidad de productos en oferta.
        g. Cargar productos de Gondola en un nuevo vector Chango, indicando luego: monto a abonar y ahorro total teniendo en cuenta los productos en oferta.
*/
struct producto{
    string nombre;
    long codigo;
    float precio;
    bool oferta;
};

producto* buscarProducto(vector<producto> gondola,long codigo){
    bool encontrado = false;
    producto* resultado;

    for (int i = 0; !encontrado && i < gondola.size(); i++){
        encontrado = gondola[i].codigo == codigo;
        if (encontrado) {
            resultado = &gondola[i];
        }
    }
    if (!encontrado){
        throw "producto no encontrado";
    }

    return resultado;
}

producto* buscarProducto(vector<producto> gondola,string nombre){
    bool encontrado = false;
    producto* resultado;

    for (int i = 0; !encontrado && i < gondola.size(); i++){
        encontrado = gondola[i].nombre == nombre;
        if (encontrado) {
            resultado = &gondola[i];
        }
    }
    if (!encontrado){
        throw "producto no encontrado";
    }

    return resultado;
}

int buscarIndiceProducto(vector<producto> gondola,long codigo){
    bool encontrado = false;
    int resultado = 0;

    for (int i = 0; !encontrado && i < gondola.size(); i++){
        encontrado = gondola[i].codigo == codigo;
        if (encontrado) {
            resultado = i;
        }
    }
    if (!encontrado){
        throw "producto no encontrado";
    }

    return resultado;
}

void cargarProducto(vector<producto> gondola,producto productoACargar){
    try {
        buscarProducto(gondola, productoACargar.codigo);
    }
    catch (...){
        gondola.push_back(productoACargar);
    }
}

void modificarPrecioDelProducto(producto* productoAModificar, float nuevoPrecio){
    productoAModificar -> precio =  nuevoPrecio;
}


//???
void quitarProducto(vector<producto> gondola, producto productoAQuitar){
    int indice = buscarIndiceProducto(productoAQuitar.codigo); // <- ?????????????
    gondola.erase(gondola.begin() + indice);
}

int cantidadDeProductosEnOferta(vector<producto> gondola,int largoGondola){
    int cantidad = 0;

    for(producto producto : gondola){
        if (producto.oferta){
            cantidad ++;
        }
    }

    return cantidad;
}

int main() {
    const int largo = 50;
    producto gondola[largo] = {nullptr};

    

    //código

    return 0;
}