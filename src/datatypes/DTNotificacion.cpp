/*
#ifndef DTNOTIFICACION
#define DTNOTIFICACION

#include <string>


using namespace std;

class DTNotificacion {
    private:
        string nombreCurso;
        string nombreIdioma;
    public:
        DTNotificacion(string nombreCurso, string nombreIdioma);
        string getNombreCurso();
        string getNombreIdioma();
        ~DTNotificacion();
        friend ostream& operator<<(ostream& os, const DTNotificacion& dtNotificacion);
};

#endif*/

#include "../../include/datatypes/DTNotificacion.h"

#include <string>
#include <iostream>

using namespace std;

DTNotificacion::DTNotificacion(string nombreCurso, string nombreIdioma) {
    this->nombreCurso = nombreCurso;
    this->nombreIdioma = nombreIdioma;
}

string DTNotificacion::getNombreCurso() {
    return this->nombreCurso;
}

string DTNotificacion::getNombreIdioma() {
    return this->nombreIdioma;
}

DTNotificacion::~DTNotificacion() {}

ostream& operator<<(ostream& os, const DTNotificacion& dtNotificacion) {
    os << "Nombre del curso: " << dtNotificacion.nombreCurso << endl;
    os << "Nombre del idioma: " << dtNotificacion.nombreIdioma << endl;
    return os;
}