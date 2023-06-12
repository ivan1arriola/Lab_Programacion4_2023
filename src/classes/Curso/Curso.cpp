#include "../../../include/classes/Curso/Curso.h"

Curso::Curso() {
    // Implementación del constructor por defecto
}

Curso::Curso(string nombre, string descripcion, Nivel nivel, bool disponible) {
    // Implementación del constructor con parámetros
}

Curso::Curso(string nombre, string descripcion, Nivel nivel, bool disponible, Idioma* idioma, Profesor* profesor, vector<Leccion*> lecciones) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->nivel = nivel;
    this->disponible = disponible;
    this->lecciones = lecciones;
    this->idioma = idioma;
    this->profesor = profesor;

    idioma->notificarSuscriptores(nombre);
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

void Curso::agregarLeccion(Leccion* leccion) {
    this->lecciones.push_back(leccion);
}

int Curso::getCantEjsTotal() {
    int total=0;
    for(vector<Leccion*>::iterator it=lecciones.begin(); it!=lecciones.end();++it){
        Leccion* l=*it;
        total=l->getCantEj();
        }
    // Implementación de la función getCantEjsTotal()
    return total;
}

float Curso::calcPromedioAvance() {
    // Implementación de la función calcPromedioAvance()
    return 0;
}

int Curso::getCantLecciones(){
    return lecciones.size();
}

Curso::~Curso() {
    // Borrar todos las lecciones

    for (long unsigned int i = 0; i < lecciones.size(); i++) {
        delete lecciones[i];
    }
}
