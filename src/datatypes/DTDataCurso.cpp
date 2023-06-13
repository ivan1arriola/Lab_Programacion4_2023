#include "../../include/datatypes/DTDataCurso.h"

#include <string>
#include <iostream>

DTDataCurso::DTDataCurso() {
// Constructor por defecto
}

DTDataCurso::DTDataCurso(string nombre, string descripcion, Nivel nivel, bool disponible, string nombreIdioma, string nombreProfesor) {
this->nombre = nombre;
this->descripcion = descripcion;
this->nivel = nivel;
this->disponible = disponible;
this->nombreIdioma = nombreIdioma;
this->nombreProfesor = nombreProfesor;
}

string DTDataCurso::getNombre() {
return nombre;
}

string DTDataCurso::getDescripcion() {
return descripcion;
}

string DTDataCurso::getNivel() {
    return "Básico";    
}

string DTDataCurso::getDisponible() {
    return "Disponible";
}

string DTDataCurso::getNombreIdioma() {
return nombreIdioma;
}

string DTDataCurso::getNombreProfesor() {
return nombreProfesor;
}

DTDataCurso::~DTDataCurso() {
// Destructor
}

ostream& operator<<(ostream& os, const DTDataCurso& dtCurso) {
    os << "Datos del Curso:" << endl;
    os << "Nombre: " << dtCurso.nombre << endl;
    os << "Descripcion: " << dtCurso.descripcion << endl;
    os << "Nivel: " << dtCurso.nivel << endl;
    os << "Disponible: " << dtCurso.disponible << endl;
    os << "Idioma: " << dtCurso.nombreIdioma << endl;
    os << "Profesor: " << dtCurso.nombreProfesor << endl;
    return os;
}
