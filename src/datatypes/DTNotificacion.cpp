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
    os << "Notificacion:" << endl;
    os << "Se creo el curso de nombre " << '"' << dtNotificacion.nombreCurso << '"' << endl;
    os << "Un curso del idioma: " << dtNotificacion.nombreIdioma;
    return os;
}
