#include "../../include/datatypes/DTDataLeccion.h"

#include <string>

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