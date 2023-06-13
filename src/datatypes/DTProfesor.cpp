#include "../../include/datatypes/DTProfesor.h"

#include <string>
#include <iostream>

DTProfesor::DTProfesor() {}

DTProfesor::DTProfesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto) : DTUsuario(nickname, contrasenia, nombre, descripcion, 0) {
    this->instituto = instituto;
}

// Getters

string DTProfesor::getInstituto() {
    return this->instituto;
}

// Destructor

DTProfesor::~DTProfesor() {}


ostream& operator<<(ostream& os, DTProfesor& dtProfesor) {
    os << "Tipo: Profesor" << endl;
    os << "Nickname: " << dtProfesor.getNickname() << endl;
    os << "Nombre: " << dtProfesor.getNombre() << endl;
    os << "Descripcion: " << dtProfesor.getDescripcion() << endl;
    os << "Instituto: " << dtProfesor.getInstituto() << endl;
    return os;
}
