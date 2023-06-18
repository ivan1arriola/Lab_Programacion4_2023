#include "../../../include/classes/Curso/Ejercicio.h"
#include "../../../include/classes/Curso/Completar.h"
#include "../../../include/classes/Curso/Traducir.h"

Ejercicio::Ejercicio() {
    // Implementación del constructor por defecto
}

Ejercicio::Ejercicio(string nombre, string descripcion) {
    // Implementación del constructor con parámetros
    this->nombre = nombre;
    this->descripcion = descripcion;
}

string Ejercicio::getNombre() {
    return nombre;
}

string Ejercicio::getDescripcion() {
    return descripcion;
}

void Ejercicio::setNombre(string nombre) {
    this->nombre = nombre;
}

void Ejercicio::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

DTEjercicio* Ejercicio::getDTEjercicio(){
    string tipo;
    string descripcion;

    if(dynamic_cast<Completar*>(this) != nullptr){
        tipo = "Completar palabras";
        // descripcion = ejCompletar->getDescripcion();
    }else if(dynamic_cast<Traducir*>(this) != nullptr){
        tipo = "Traducir";
    }

    return new DTEjercicio(tipo, this->descripcion);
}

Ejercicio::~Ejercicio() {
    // Implementación del destructor
}
