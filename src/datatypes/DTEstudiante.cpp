#include "../../include/datatypes/DTEstudiante.h"

#include <string>
#include <iostream>

// Constructor
DTEstudiante::DTEstudiante() {}

DTEstudiante::DTEstudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, DTDate *fechaNacimiento) : DTUsuario(nickname, contrasenia, nombre, descripcion, 1) {
    this->pais = pais;
    this->fechaNacimiento = fechaNacimiento;
}

// Getters

string DTEstudiante::getPais() {
    return this->pais;
}

DTDate* DTEstudiante::getFechaNacimiento() {
    return this->fechaNacimiento;
}


// Destructor

DTEstudiante::~DTEstudiante() {
    delete this->fechaNacimiento;
}

void DTEstudiante::imprimir(ostream& os) {
    os << "Nickname: " << this->getNickname() << endl;
    os << "Nombre: " << this->getNombre() << endl;
    os << "Descripcion: " << this->getDescripcion() << endl;
    os << "Pais: " << this->getPais() << endl;
    os << "Fecha de nacimiento: " << this->getFechaNacimiento() << endl;
}

