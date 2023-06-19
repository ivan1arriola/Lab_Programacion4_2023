#include "../../include/datatypes/DTDataCursoAInscribir.h"

#include <string>
#include <iostream>

DTDataCursoAInscribir::DTDataCursoAInscribir() {
// Constructor por defecto
}

DTDataCursoAInscribir::DTDataCursoAInscribir(string nombre, string descripcion, Nivel nivel, string nombreIdioma, string nombreProfesor, int cantLecciones, int cantEjercicios) {
this->nombre = nombre;
this->descripcion = descripcion;
this->nivel = nivel;
this->nombreIdioma = nombreIdioma;
this->nombreProfesor = nombreProfesor;
this->cantLecciones = cantLecciones;
this->cantEjercicios = cantEjercicios;
}

string DTDataCursoAInscribir::getNombre() {
return nombre;
}

string DTDataCursoAInscribir::getDescripcion() {
return descripcion;
}

string DTDataCursoAInscribir::getNivel() {
    return "Básico";    
}

string DTDataCursoAInscribir::getNombreIdioma() {
return nombreIdioma;
}

string DTDataCursoAInscribir::getNombreProfesor() {
return nombreProfesor;
}

int DTDataCursoAInscribir::getCantLecciones(){
  return cantLecciones;
}

int DTDataCursoAInscribir::getCantEjercicios(){
  return cantEjercicios;
}

DTDataCursoAInscribir::~DTDataCursoAInscribir() {
// Destructor
}

ostream& operator<<(ostream& os, const DTDataCursoAInscribir& dtDataCursoAInscribir) {
    os << "Datos del Curso:" << endl;
    os << "Nombre: " << dtDataCursoAInscribir.nombre << endl;
    os << "Descripcion: " << dtDataCursoAInscribir.descripcion << endl;
    os << "Nivel: " << dtDataCursoAInscribir.nivel << endl;
    os << "Idioma: " << dtDataCursoAInscribir.nombreIdioma << endl;
    os << "Profesor: " << dtDataCursoAInscribir.nombreProfesor << endl;
    os << "Cantidad de lecciones: " << dtDataCursoAInscribir.cantLecciones << endl;
    os << "Cantidad de ejercicios: " << dtDataCursoAInscribir.cantEjercicios << endl;
    return os;
}
