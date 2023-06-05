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


void DTProfesor::imprimir(ostream& os) {
    os << "Nickname: " << this->getNickname() << endl;
    os << "Nombre: " << this->getNombre() << endl;
    os << "Descripcion: " << this->getDescripcion() << endl;
    os << "Instituto: " << this->getInstituto() << endl;
}
