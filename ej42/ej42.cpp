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


//sobrecarca de buscarProducto para que tome tanto el código de barras como el nombre de producto como parametro de busqueda
producto* buscarProducto(vector<producto> gondola,long codigo){
    bool encontrado = false;
    producto* resultado;

    for (int i = 0; !encontrado && i < gondola.size(); i++){
        encontrado = gondola.at(i).codigo == codigo;
        if (encontrado) {
            resultado = &gondola.at(i);
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
            resultado = &gondola.at(i);
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
        encontrado = gondola.at(i).codigo == codigo;
        if (encontrado) {
            resultado = i;
        }
    }
    if (!encontrado){
        throw "producto no encontrado";
    }

    return resultado;
}

void cargarProducto(vector<producto>* gondola,producto productoACargar){
    try {
        buscarProducto(*gondola, productoACargar.codigo);
    }
    catch (...){
        gondola->push_back(productoACargar);
    }
}

void modificarPrecioDelProducto(producto* productoAModificar, float nuevoPrecio){
    productoAModificar -> precio =  nuevoPrecio;
}



void quitarProducto(vector<producto>* gondola, long codigoProductoAQuitar){
    int indice = buscarIndiceProducto(*gondola, codigoProductoAQuitar);
    gondola->erase(gondola->begin() + indice);
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

void imprimirMenu(){
    //Reponé La Góndola Carajo <- (cambiar por otro mas apropiado despues)
    cout << "BIENVENIDO/A AL SISTEMA DE STOCK ELECTRÓNICO R.L.G.C." << endl
         << "-----------------------------------------------------" << endl
         << "¿qué operación desea realizar?"                        << endl
         << "-----------------------------------------------------" << endl
         << "a - Agregar un producto nuevo a la góndola"            << endl
         << "b - Buscar un producto por su nombre"                  << endl
         << "c - Buscar un producto por su código de barrras"       << endl
         << "d - Modificar precio de un producto"                   << endl
         << "e - Quitar un producto de la góndola"                  << endl
         << "f - Ver la cantidad de productos en oferta"            << endl
         << "g - Agregar un producto al carrito"                    << endl
         << "h - Salir"                                             << endl
         << "-----------------------------------------------------" << endl
         << "Opción elegida: "                                      << endl;
}

void limpiarPantalla(){
    cout << "\033[H\033[2J" << flush;
}

void agregarProducto_tui(vector<producto>* gondola){
    producto nuevoProducto;
    char seleccion = 'N';
    bool existe = false;
    string nombreNuevoProducto = "";
    long codigoNuevoProducto = 0;

    cout << "Ingrese nombre del producto (ej: fideos marolio): ";
    getline(cin,nombreNuevoProducto); 
    try {
            buscarProducto(*gondola, nombreNuevoProducto); //si tira excepcion ta bien porque no existe y se saltea todo el resto
            existe = true;
            limpiarPantalla();
            cout << "error: ya existe un producto con ese nombre" << endl;
        }
        catch(...) {
            nuevoProducto.nombre = nombreNuevoProducto;
        }
    limpiarPantalla();
    cout << "Ingrese precio del producto (ej: 1599.99): ";
    cin >> nuevoProducto.precio; 
    limpiarPantalla();
    do{
        cout << "Ingrese código del producto (ej: 73452): ";
        cin >> codigoNuevoProducto;
        try {
            buscarProducto(*gondola, codigoNuevoProducto); //si tira excepcion ta bien porque no existe y se saltea todo el resto
            existe = true;
            limpiarPantalla();
            cout << "error: ya existe un producto con ese código." << endl;
        }
        catch(...) {
            nuevoProducto.codigo = codigoNuevoProducto;
        }
    }
    while (existe);
    limpiarPantalla();
    cout << "¿poner el producto en oferta? (s/N): ";
    cin >> seleccion;
    nuevoProducto.oferta = (seleccion == 'S' || seleccion == 's');

    cargarProducto(gondola, nuevoProducto);

    try {
        buscarProducto(*gondola,nuevoProducto.codigo);
        cout << "Producto agregado con éxito" << endl;
    }
    catch (...){
        cout << "Error: Hubo un error al agregar el producto" << endl;
    }

}

int main() {

    vector<producto> gondola = {};
    vector<producto> carrito = {};
    char opcion = ' ';
    bool salir = false;
    
    limpiarPantalla();
    do {
        imprimirMenu();
        cin >> opcion;

        switch (opcion) {
            case 'a':
                agregarProducto_tui(&gondola);
                break;
            case 'b':
                break;
            case 'c':
                break;
            case 'd':
                break;
            case 'e':
                break;
            case 'f':
                break;
            case 'g':
                break;
            case 'h':
                cout << "Gracias! Vuelva pronto!" << endl;
                salir = true;
                break;
            default:
                limpiarPantalla();
                cout << "Opción Inválida" << endl;
                break;
        }
    }
    while(!salir);

    return 0;
}