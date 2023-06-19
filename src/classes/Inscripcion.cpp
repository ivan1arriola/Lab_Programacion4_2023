#include "../../include/classes/Inscripcion.h"
#include "../../include/datatypes/DTDate.h"

// Constructores
Inscripcion::Inscripcion() {
    fechaInscripcion = nullptr;
    aprobado = false;
    estudiante = nullptr;
    curso = nullptr;
}


Inscripcion::Inscripcion(DTDate* fechaInscripcion, bool aprobado, Estudiante* estudiante, Curso* curso) {
    this->fechaInscripcion = fechaInscripcion;
    this->aprobado = aprobado;
    this->estudiante = estudiante;
    this->curso = curso;
    this->cantEjsAprobados = 0;

    estudiante->agregarInscripcion(curso->getNombre(), this);
    curso->agregarInscrip(estudiante->getNickname(), this);
    this->ejNoAprobados=curso->getLecciones().back()->getEjercicios();
}

void Inscripcion::aproboEjercicio(){
    this->cantEjsAprobados = this->cantEjsAprobados + 1;
}

Inscripcion::Inscripcion(DTDate* fechaInscripcion, bool aprobado, Estudiante* estudiante, Curso* curso,set<Ejercicio*> ejnoaprob) {
    this->fechaInscripcion = fechaInscripcion;
    this->aprobado = aprobado;
    this->estudiante = estudiante;
    this->curso = curso;
    estudiante->agregarInscripcion(curso->getNombre(), this);
    curso->agregarInscrip(estudiante->getNickname(), this);
    this->ejNoAprobados=curso->getLecciones().back()->getEjercicios();
}

// Getters
DTDate* Inscripcion::getFechaInscripcion() {
    return fechaInscripcion;
}

bool Inscripcion::getAprobado() {
    return aprobado;
}

set<Ejercicio*> Inscripcion::getejAprobados(){
    return ejAprobados;
}

set<Ejercicio*> Inscripcion::getejNoAprobados(){
    return ejNoAprobados;
}

// Setters
void Inscripcion::setFechaInscripcion(DTDate* date) {
    fechaInscripcion = date;
}

void Inscripcion::setAprobado(bool aprobado) {
    this->aprobado = aprobado;
}

void Inscripcion::setejAprobado(Ejercicio* e){
    this->ejAprobados.insert(e);
    this->ejNoAprobados.erase(e);    
}

void Inscripcion::setejNoAprobado(Ejercicio*){}

// Métodos
string Inscripcion::obtenerNombreCurso() {
    if (curso != nullptr) {
        return curso->getNombre();
    }
    return "";
}

float Inscripcion::calcPorcentajeAvance() {
    if (curso != nullptr) {
        if(curso->getCantEjsTotal() == 0){
            return 0;
        }else{
            return (getCantEjsAprob() / curso->getCantEjsTotal()) * 100.0;
        }
    }
    return 0.0;
}

float Inscripcion::getCantEjsAprob() {
    if (curso != nullptr) {
        return cantEjsAprobados;
    }
    return 0.0;
}

DTInscripcion* Inscripcion::getDTInscripcion(){
    return new DTInscripcion(this->estudiante->getNickname(), this->fechaInscripcion);
}

Inscripcion::~Inscripcion(){
    delete fechaInscripcion;
    if(estudiante!=NULL)estudiante=NULL;
    if(curso!=NULL)curso=NULL;
}

float Inscripcion::getcantEjAprobados(){return cantEjsAprobados;}

void Inscripcion::setcantEjAprobados(){
    cantEjsAprobados=cantEjsAprobados+1;
}