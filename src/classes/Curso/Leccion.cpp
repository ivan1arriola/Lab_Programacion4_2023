#include "../../../include/classes/Curso/Leccion.h"

Leccion::Leccion() {
    // Implementación del constructor por defecto
}

Leccion::Leccion(string descripcion) {
    // Implementación del constructor con parámetros
}

Leccion::Leccion(string tema, string objetivo) {
    this->tema = tema;
    this->objetivo = objetivo;
}

string Leccion::getTema() {
    return tema;
}

string Leccion::getObjetivo() {
    return objetivo;
}

void Leccion::setTema(string tema) {
    this->tema = tema;
}

void Leccion::setObjetivo(string objetivo) {
    this->objetivo = objetivo;
}

void Leccion::crearEjercicioYAgregarlo(string desc) {
    // Implementación de la función crearEjercicioYAgregarlo()
}

set<Ejercicio> Leccion::getEjercicios() {
    // Implementación de la función getEjercicios()
    return set<Ejercicio>();
}

Leccion::~Leccion() {
    // Borrar todos los ejercicios
}
