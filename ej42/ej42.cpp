#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
    42) Definir un vector Gondola en donde puedan almacenar datos de a lo sumo 50 productos del supermercado.
        Cada producto se define por su nombre, código de barras, precio y un indicador si está en oferta o no (si estuviera en oferta al precio se le debe descontar un 10%).
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

//funciones "internas" (modifican los vectores)

//sobrecarca de buscarProducto para que tome tanto el código de barras como el nombre de producto como parametro de busqueda
producto* buscarProducto(vector<producto>* gondola,long codigo){
    bool encontrado = false;
    producto* resultado;

    for (int i = 0; !encontrado && i < gondola -> size(); i++){
        encontrado = gondola -> at(i).codigo == codigo;
        if (encontrado) {
            resultado = &gondola -> at(i);
        }
    }
    if (!encontrado){
        throw "producto no encontrado";
    }

    return resultado;
}

producto* buscarProducto(vector<producto>* gondola,string nombre){
    bool encontrado = false;
    producto* resultado;

    for (int i = 0; !encontrado && i < gondola -> size(); i++){
        encontrado = gondola -> at(i).nombre == nombre;
        if (encontrado) {
            resultado = &gondola -> at(i);
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
        buscarProducto(gondola, productoACargar.codigo);
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

void agregarProductoAlCarrito(vector<producto>* carrito,producto productoACargar){
    carrito -> push_back(productoACargar);
}

float calcularTotalCarrito(vector<producto> carrito){
    float total = 0;

    for (producto producto : carrito) {
        total += producto.precio; 
    }

    return total;
}

float calcularAhorro(vector<producto> carrito){
    float ahorro = 0;

    for (producto producto : carrito){
        if (producto.oferta){
            ahorro += producto.precio / 10;
        }
    }

    return ahorro;
}

//funciones de utilidad

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
         << "f - Ver opciones del chango"                           << endl
         << "g - Salir"                                             << endl
         << "-----------------------------------------------------" << endl
         << "Opción elegida: "                                      ;
}

// Source - https://stackoverflow.com/a/52895729
// Posted by Joma, modified by community. See post 'Timeline' for change history
// Retrieved 2026-09-09, License - CC BY-SA 4.0

void limpiarPantalla()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}


float redondearA2Decimales(float numero){
    return float(round(numero*100)/100);
}


//funciones "externas" (interacción del usuario implementadas con las funciones internas)

producto* buscarProducto_tui(vector<producto>* gondola){
    string busqueda = "";
    producto* resultado = nullptr;

    limpiarPantalla();

    cout << "Ingrese el nombre o código del producto: ";
    cin >> busqueda;

    if(is_number(busqueda)){
        try{
            resultado = buscarProducto(gondola,stol(busqueda));
            return resultado;
        }
        catch(char const* error){
            throw error;
        }
    }
    else {
        try{
            resultado = buscarProducto(gondola,busqueda);
            return resultado;
        }
        catch(char const* error){
            throw error;
        }
    }
}

void agregarProducto_tui(vector<producto>* gondola){
    producto nuevoProducto;
    char seleccion = 'N';
    bool existe = false;
    string nombreNuevoProducto = "";
    long codigoNuevoProducto = 0;

    limpiarPantalla();
    do{
        cout << "Ingrese nombre del producto (ej: fideos): ";
        cin >> nombreNuevoProducto;
        try {
                buscarProducto(gondola, nombreNuevoProducto); //si tira excepcion ta bien porque no existe y se saltea todo el resto
                existe = true;
                limpiarPantalla();
                cout << "error: ya existe un producto con ese nombre" << endl;
            }
            catch(...) {
                existe = false;
                nuevoProducto.nombre = nombreNuevoProducto;
            }
    }
    while (existe);
    limpiarPantalla();
    do{
        cout << "Ingrese código del producto (ej: 73452): ";
        cin >> codigoNuevoProducto;
        try {
            buscarProducto(gondola, codigoNuevoProducto); //si tira excepcion ta bien porque no existe y se saltea todo el resto
            existe = true;
            limpiarPantalla();
            cout << "error: ya existe un producto con ese código." << endl;
        }
        catch(...) {
            existe = false;
            nuevoProducto.codigo = codigoNuevoProducto;
        }
    }
    while (existe);
    limpiarPantalla();
    cout << "Ingrese precio del producto (ej: 1599.99): ";
    cin >> nuevoProducto.precio; 
    limpiarPantalla();
    cout << "¿poner el producto en oferta? (s/N): ";
    cin >> seleccion;
    nuevoProducto.oferta = (seleccion == 'S' || seleccion == 's');

    cargarProducto(gondola, nuevoProducto);

    try {
        buscarProducto(gondola,nuevoProducto.codigo);
        cout << "Producto agregado con éxito" << endl;
    }
    catch (...){
        cout << "Error: Hubo un error al agregar el producto" << endl;
    }

}

int mostrarProducto_tui(vector<producto>* gondola){
    float precio = 0;
    string oferta = "";
    producto resultado;
    
    try{
        resultado = *buscarProducto_tui(gondola);
    }
    catch(char const* error){
        cout << error << endl;
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


void agregarProductoAChango_tui(vector<producto>* gondola, vector<producto>* carrito){
    producto resultado;
    char eleccion = 'N';
    
    try{
        resultado = *buscarProducto_tui(gondola);
        carrito -> push_back(resultado);
        cout << "producto agregado con éxito" << endl;
    }
    catch(char const* error){
        cout << error << endl << "desea intentar nuevamente? (s/N): ";
        cin >> eleccion;

        if (eleccion == 'S' || eleccion == 's') {
            limpiarPantalla();
            agregarProductoAChango_tui(gondola,carrito);
        }
    }
}

void mostrarChango_tui(vector<producto> carrito){
    limpiarPantalla();
    cout
            << "-----------------------------------------------------" << endl
            << "Carrito:" <<endl
            << "-----------------------------------------------------" << endl;

    if (carrito.size() > 0){
        for( producto producto : carrito){
            cout
            << producto.nombre << " - $" << redondearA2Decimales(producto.precio) << endl;
        }
        float total = calcularTotalCarrito(carrito), descuento = calcularAhorro(carrito), ahorro = total - descuento;
        cout
            << "-----------------------------------------------------" << endl
            << "Total: $" << redondearA2Decimales(total)               << endl
            << "Descuento: -$" << redondearA2Decimales(descuento)      << endl
            << "Total con descuentos: $"  << redondearA2Decimales(ahorro) << endl
            << "-----------------------------------------------------" << endl;            
    }
    else {
        cout << "El chango está vacio, agregue algunos productos." << endl
             << "-----------------------------------------------------" << endl;

    }

}

void chango_tui(vector<producto>gondola, vector<producto>* carrito){
    bool volver = false;
    char opcion = ' ';
    limpiarPantalla();
    do{
        cout
            << "-----------------------------------------------------" << endl
            << "Opciones del changuito"                                << endl
            << "-----------------------------------------------------" << endl
            << "a - Agregar un producto"                               << endl
            << "b - Ver total"                                         << endl
            << "c - volver al menú anterior"                           << endl
            << "-----------------------------------------------------" << endl
            << "Opción elegida: ";
        cin >> opcion;

        switch (opcion) {
            case 'a':
                agregarProductoAChango_tui(&gondola,carrito);
                break;
            case 'b':
                mostrarChango_tui(*carrito);
                break;
            case 'c':
                volver = true;
                break;
            default:
            limpiarPantalla();
            cout << "Opción inválida" << endl;
            break;
        }
    }
    while (!volver);

}

int main() {

    vector<producto> gondola = {};
    vector<producto> chango = {};
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
                chango_tui(gondola,&chango);
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