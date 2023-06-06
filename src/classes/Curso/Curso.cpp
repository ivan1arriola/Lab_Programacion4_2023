#include "../../../include/classes/Curso/Curso.h"

Curso::Curso() {
    // Implementación del constructor por defecto
}

Curso::Curso(string nombre, string descripcion, Nivel nivel, bool disponible) {
    // Implementación del constructor con parámetros
}

string Curso::getNombre() {
    return nombre;
}

string Curso::getDescripcion() {
    return descripcion;
}

Nivel Curso::getNivel() {
    return nivel;
}

bool Curso::getDisponible() {
    return disponible;
}

void Curso::setNombre(string nombre) {
    this->nombre = nombre;
}

void Curso::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

void Curso::setNivel(Nivel nivel) {
    this->nivel = nivel;
}

void Curso::setDisponible(bool disponible) {
    this->disponible = disponible;
}

set<string> Curso::obtenerEjNoAprobados() {
    // Implementación de la función obtenerEjNoAprobados()
    return set<string>();
}

void Curso::agregarALeccion(string desc) {
    // Implementación de la función agregarALeccion()
}

float Curso::getCantEjsTotal() {
    // Implementación de la función getCantEjsTotal()
    return 0;
}

float Curso::calcPromedioAvance() {
    // Implementación de la función calcPromedioAvance()
    return 0;
}

Curso::~Curso() {
    // Implementación del destructor
}
