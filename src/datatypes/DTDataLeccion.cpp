#include "../../include/datatypes/DTDataLeccion.h"

#include <string>
#include <iostream>

using namespace std;

DTDataLeccion::DTDataLeccion(string tema, string objetivo) {
    this->tema = tema;
    this->objetivo = objetivo;
}

DTDataLeccion::DTDataLeccion(string tema, string objetivo, set<DTEjercicio *> ejercicios) {
    this->tema = tema;
    this->objetivo = objetivo;
    this->ejercicios = ejercicios;
}

string DTDataLeccion::getTema() {
    return this->tema;
}

string DTDataLeccion::getObjetivo() {
    return this->objetivo;
}

DTDataLeccion::~DTDataLeccion() {
    for (set<DTEjercicio *>::iterator it = this->ejercicios.begin(); it != this->ejercicios.end(); ++it) {
        delete *it;
    }
}

ostream& operator<<(ostream& os, const DTDataLeccion& dtLeccion) {
    os << "     " << "Datos de la leccion:" << endl;
    os << "     " << "-------------------" << endl;
    os << "     " << "Tema: " << dtLeccion.tema << endl;
    os << "     " << "Objetivo: " << dtLeccion.objetivo << endl;
    os << endl;
    if(dtLeccion.ejercicios.size() > 0){
        os << "     " << "Ejercicios de la leccion: " << endl;
        for (set<DTEjercicio *>::iterator it = dtLeccion.ejercicios.begin(); it != dtLeccion.ejercicios.end(); ++it) {
            os << **it << endl;
        }
    } else {
        os << "     " << "     " << "No hay ejercicios en esta leccion." << endl;
    }
    return os;
}
