#include "../../include/datatypes/DTEjercicio.h"

#include <string>

using namespace std;

DTEjercicio::DTEjercicio() {}

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