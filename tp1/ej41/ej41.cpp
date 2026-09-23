#include <iostream>
#include <vector>
using namespace std;

/*
    41) Definir un vector Agenda, en donde se pueda guardar los datos de, a lo sumo, 50 personas (definidas en el ej. anterior) y permita:
        a. Cargar los datos en la Agenda.                               [ ]
        b. Poder buscar el teléfono de una persona indicando su nombre. [x]
        c. Poder buscar el nombre de una persona indicando su teléfono. [x]
        d. Poder modificar el número de teléfono de alguna persona.     [x] 
        e. Poder agregar un nuevo contacto.                             [X]
        f. Poder dar de baja a un contacto.                             [X]
*/
struct persona {
    string nombre;
    int telefono;
};

persona buscarContacto(vector<persona> agenda, string nombre){
    bool encontrado = false;
    persona resultado;

    for (int i = 0; !encontrado && i < agenda.size(); i++){
        encontrado = agenda[i].nombre == nombre;
        if (encontrado){
            resultado = agenda[i];
        }
    }

    if(!encontrado){
        throw "contacto no encontrado";
    }

    return resultado;
}

persona buscarContacto(vector<persona> agenda, int telefono){
    bool encontrado = false;
    persona resultado;

    for (int i = 0; !encontrado && i < agenda.size(); i++){
        encontrado = agenda[i].telefono == telefono;
        if (encontrado){
            resultado = agenda[i];
        }
    }

    if(!encontrado){
        throw "contacto no encontrado";
    }

    return resultado;
}

string buscarNombrePorNumero(vector<persona>agenda, int telefono){
    bool encontrado = false;
    string resultado = "";

    try {
        resultado = buscarContacto(agenda, telefono).nombre;
    }
    catch (...) {
        resultado = "contacto no encontrado";
    }

    return resultado;
}

int buscarNumeroPorNombre(vector<persona>agenda, string nombre){
    bool encontrado = false;
    int resultado = 0;

    try {
        resultado = buscarContacto(agenda, nombre).telefono;
    }
    catch (...) {
        resultado = 0;
    }

    return resultado;
}

void agregarContacto(vector<persona> agenda, persona nuevoContacto){
    agenda.push_back(nuevoContacto);
}

string eliminarContacto(vector<persona> agenda, persona contactoABorrar){
    bool encontrado = false;

    for (int i = 0; !encontrado && i < agenda.size(); i++){
        encontrado = agenda[i].nombre == contactoABorrar.nombre && agenda[i].telefono == contactoABorrar.telefono;
        if (encontrado){
            agenda.erase(agenda.begin() + i);
        }
    }
}

string modificarNumeroDeContacto(vector<persona> agenda, string nombre, int nuevoTelefono){
    try {
        persona contacto = buscarContacto(agenda, nombre);
        contacto.telefono = nuevoTelefono;
    }
    catch (...){
        return "contacto no encontrado";
    }

    return "contacto modificado con éxito";
}

int main() {

    //código

    return 0;
}