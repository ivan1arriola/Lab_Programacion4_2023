#include "../../include/datatypes/DTDataLeccion.h"

#include <string>
#include <iostream>

using namespace std;

DTDataLeccion::DTDataLeccion(string tema, string objetivo) {
    this->tema = tema;
    this->objetivo = objetivo;
}

string DTDataLeccion::getTema() {
    return this->tema;
}

string DTDataLeccion::getObjetivo() {
    return this->objetivo;
}

DTDataLeccion::~DTDataLeccion() {}

ostream& operator<<(ostream& os, const DTDataLeccion& dtLeccion) {
    // os << "Datos de la leccion:" << endl;
    os << "Tema: " << dtLeccion.tema << endl;
    os << "Objetivo: " << dtLeccion.objetivo << endl;
    return os;
}
