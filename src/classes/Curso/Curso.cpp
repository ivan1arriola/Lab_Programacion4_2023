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
    this->inscripciones = map<string, Inscripcion*>();
}

// Curso::Curso(string nombre, string descripcion, Nivel nivel, bool disponible, Idioma* idioma, Profesor* profesor, vector<Leccion*> lecciones, set<Curso*> cursosPrevios) {
//     this->nombre = nombre;
//     this->descripcion = descripcion;
//     this->nivel = nivel;
//     this->disponible = disponible;
//     this->lecciones = lecciones;
//     this->idioma = idioma;
//     this->profesor = profesor;
//     this->cursosPrevios = cursosPrevios;
// }

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
vector<Leccion *> Curso::getLecciones(){
    return lecciones;
}

set<Curso*> Curso::getCursosPrevios(){
    return cursosPrevios;
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

void Curso::setCursosPrevios(set<Curso*> cursosPrevios){
    this->cursosPrevios = cursosPrevios;
}

set<string> Curso::obtenerEjNoAprobados() {
    // Implementación de la función obtenerEjNoAprobados()
    return set<string>();
}

void Curso::agregarLeccion(Leccion* leccion) {
    this->lecciones.push_back(leccion);
}

// void Curso::agregarCursoPrevio(Curso* cursoPrevio){
//     this->cursosPrevios.insert(cursoPrevio);
// }

float Curso::getCantEjsTotal() {
    int total=0;
    for(vector<Leccion*>::iterator it=lecciones.begin(); it!=lecciones.end();++it){
        Leccion* l=*it;
        total=l->getCantEj();
        }

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
    if (idioma!=NULL)idioma=NULL;
    if(profesor!=NULL)profesor=NULL;

    for (vector<Leccion*>::iterator it=lecciones.begin(); it!=lecciones.end(); ++it) {
        delete *it;
    }
    
    for (map<string,Inscripcion*>::iterator it=inscripciones.begin();it!=inscripciones.end();++it){
        delete it->second;
    }
}

DTDataCurso* Curso::getDT() {
    return new DTDataCurso(nombre, descripcion, nivel, disponible, idioma->getNombre(), profesor->getNombre());
}

DTDataCursoAInscribir* Curso::getDTAInscribir() {
    return new DTDataCursoAInscribir(nombre, descripcion, nivel, idioma->getNombre(), profesor->getNombre(), this->getCantLecciones(), this->getCantEjsTotal());
}

map<string, Inscripcion*> Curso::getInscripciones() {
    return inscripciones;
}

void Curso::agregarInscrip(string nickE, Inscripcion* i){
    this->inscripciones[nickE] = i;
}