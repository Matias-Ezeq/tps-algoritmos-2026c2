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


// Source - https://stackoverflow.com/a/4654718
// Posted by Charles Salvia, modified by community. See post 'Timeline' for change history
// Retrieved 2026-09-08, License - CC BY-SA 4.0
bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}



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

int cantidadDeProductosEnOferta(vector<producto> gondola){
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
         << "b - Buscar un producto"                                << endl
         << "c - Modificar precio de un producto"                   << endl
         << "d - Quitar un producto de la góndola"                  << endl
         << "e - Ver la cantidad de productos en oferta"            << endl
         << "f - Agregar un producto al carrito"                    << endl
         << "g - Salir"                                             << endl
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

producto* buscarProducto_tui(vector<producto>* gondola){
    string busqueda = "";
    producto resultado;
    cout << "Ingrese el nombre o código del producto: ";
    getline(cin,busqueda);

    if(is_number(busqueda)){
        try{
            resultado = *buscarProducto(*gondola,stol(busqueda));
        }
        catch(string error){
        cout << error;
        }
    }
    else {
        try{
            resultado = *buscarProducto(*gondola,busqueda);
        }
        catch(string error){
        cout << error;
        }
    }
}

int mostrarProducto_tui(vector<producto>* gondola){
    float precio = 0;
    string oferta = "";
    producto resultado;
    
    try{
        resultado = *buscarProducto_tui(gondola);
    }
    catch(...){
        return 1;
    }

    if (resultado.oferta){
        precio = resultado.precio - (resultado.precio / 10);
        oferta = "(OFERTA! 10% OFF)";
    }
    else {
        precio = resultado.precio;
    }

    cout << "Nombre: "              << resultado.nombre << endl
         << "Precio: "              << precio           << oferta << endl
         << "Codigo de barras: "    << resultado.codigo << endl;

    return 0;
}

int modificarPrecio_tui(vector<producto>* gondola){
    producto* resultado;
    try{
        resultado = buscarProducto_tui(gondola);
    }
    catch(...){
        return 1;
    }

    cout << "Ingrese el nuevo precio: ";
    cin >> resultado -> precio;

    cout << "precio actualizado exitosamente" << endl;

    return 0;
}

int eliminarProducto_tui(vector<producto>* gondola){
    producto resultado;
    try{
        resultado = *buscarProducto_tui(gondola);
    }
    catch(...){
        return 1;
    }

    quitarProducto(gondola, resultado.codigo); //modificar esta función para agregar las comprobaciones correspondientes

    cout << "Producto eliminado con éxito"<<endl;


    return 0;
}

void contarOfertas_tui(vector<producto> gondola) {
    cout << "actualmente hay " << cantidadDeProductosEnOferta(gondola) << " productos en oferta" << endl;
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
                mostrarProducto_tui(&gondola);
                break;
            case 'c':
                modificarPrecio_tui(&gondola);
                break;
            case 'd':
                eliminarProducto_tui(&gondola);
                break;
            case 'e':
                contarOfertas_tui(gondola);
                break;
            case 'f':
                break;
            case 'g':
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