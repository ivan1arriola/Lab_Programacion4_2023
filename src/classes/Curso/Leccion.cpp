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

Leccion::Leccion(string tema,string objetivo,set<Ejercicio*> ejercicios){
    this->tema=tema;
    this->objetivo=objetivo;
    this->ejercicios=ejercicios;
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

set<Ejercicio*> Leccion::getEjercicios() {
    // Implementación de la función getEjercicios()
    return ejercicios;
}

int Leccion::getCantEj(){
    return ejercicios.size();
}

Leccion::~Leccion() {
    // Borrar todos los ejercicios
}
