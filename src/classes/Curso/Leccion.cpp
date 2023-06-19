#include "../../../include/classes/Curso/Leccion.h"
#include "../../../include/classes/Curso/Completar.h"
#include "../../../include/classes/Curso/Traducir.h"

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

Leccion::Leccion(string tema ,string objetivo, set<Ejercicio*> ejercicios){
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

void Leccion::crearEjercicioCompletarYAgregarlo(string nombre, string desc, string fraseCompletar, vector<string> palabrasFaltantes) {
    // Completar* ejCompletar = dynamic_cast<Completar*>("", desc, fraseCompletar, palabrasFaltantes);
    Completar *ejCompletar = new Completar(desc, fraseCompletar, palabrasFaltantes);

    ejercicios.insert(ejCompletar);
    
}

void Leccion::crearEjercicioTraducirYAgregarlo(string nombre, string desc, string fraseTraducir, string fraseTraducida){
    Traducir *ejTraducir = new Traducir(desc, fraseTraducir, fraseTraducida);

    ejercicios.insert(ejTraducir);
}

set<Ejercicio*> Leccion::getEjercicios() {
    // Implementación de la función getEjercicios()
    return ejercicios;
}

int Leccion::getCantEj(){
    return ejercicios.size();
}

DTDataLeccion* Leccion::getDTLeccion(){
    set<DTEjercicio*> dtEjercicios;
    for (set<Ejercicio*>::iterator it=ejercicios.begin(); it!=ejercicios.end();++it) {
        dtEjercicios.insert((*it)->getDTEjercicio());
    }
    return new DTDataLeccion(tema, objetivo, dtEjercicios);
}

Leccion::~Leccion() {
    for (set<Ejercicio*>::iterator it=ejercicios.begin(); it!=ejercicios.end();++it) {
        delete *it;        
    }
    ejercicios.clear();
    // Borrar todos los ejercicios
}
