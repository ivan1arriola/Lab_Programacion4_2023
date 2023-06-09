#include "../../include/datatypes/DTDataCurso.h"

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