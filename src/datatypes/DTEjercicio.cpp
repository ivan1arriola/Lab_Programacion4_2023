#include "../../include/datatypes/DTEjercicio.h"

#include <string>
#include <iostream>

using namespace std;

DTEjercicio::DTEjercicio() {}

DTEjercicio::DTEjercicio(string nombre, string tipoEjercicio, string desc){
    this->tipoEjercicio = tipoEjercicio;
    this->desc = desc;
}

// DTEjercicio::DTEjercicio(string nombre, string tipoEjercicio, string desc, set<DTEjercicio*> ejercicios){

// }

DTEjercicio::DTEjercicio(string tipoEjercicio, string desc) {
    this->tipoEjercicio = tipoEjercicio;
    this->desc = desc;
}



string DTEjercicio::getTipoEjercicio() {
    return this->tipoEjercicio;
}

string DTEjercicio::getDesc() {
    return this->desc;
}

DTEjercicio::~DTEjercicio() {}

ostream& operator<<(ostream& os, const DTEjercicio& dtEjercicio) {
    os << "     " << "     " << "Datos del Ejercicio :" << endl;
    os << "     " << "     " << "-------------------" << endl;
    os << "     " << "     " << "Descripción: " << dtEjercicio.desc << endl;
    os << "     " << "     " << "Tipo de ejercicio: " << dtEjercicio.tipoEjercicio << endl;
    return os;
}