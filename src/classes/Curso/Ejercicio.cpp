#include "../../../include/classes/Curso/Ejercicio.h"

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

Ejercicio::~Ejercicio() {
    // Implementación del destructor
}
