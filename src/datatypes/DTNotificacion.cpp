#include "../../include/datatypes/DTNotificacion.h"

#include <string>
#include <iostream>

using namespace std;

DTNotificacion::DTNotificacion(string nombreCurso, string nombreIdioma) {
    this->nombreCurso = nombreCurso;
    this->nombreIdioma = nombreIdioma;
}

string DTNotificacion::getNombreCurso() const {
    return this->nombreCurso;
}

string DTNotificacion::getNombreIdioma() const {
    return this->nombreIdioma;
}


DTNotificacion::~DTNotificacion() {}



ostream& operator<<(ostream& os, const DTNotificacion& dtNotificacion) {
    os << "Nombre del curso: " << dtNotificacion.nombreCurso << endl;
    os << "Nombre del idioma: " << dtNotificacion.nombreIdioma << endl;
    return os;
}
