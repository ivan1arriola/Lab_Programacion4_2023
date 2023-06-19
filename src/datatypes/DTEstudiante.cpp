#include "../../include/datatypes/DTEstudiante.h"

#include <string>
#include <iostream>

// Constructor
DTEstudiante::DTEstudiante() {}

DTEstudiante::DTEstudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, DTDate *fechaNacimiento) : DTUsuario(nickname, contrasenia, nombre, descripcion, 1) {
    this->pais = pais;
    if (fechaNacimiento == NULL) {
        this->fechaNacimiento = NULL;
    } else {
        this->fechaNacimiento = new DTDate(fechaNacimiento); // Constructor por copia
    }
}

DTEstudiante::DTEstudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais) : DTUsuario(nickname, contrasenia, nombre, descripcion, 1) {
    this->pais = pais;
    this->fechaNacimiento = NULL;
}

// Getters

string DTEstudiante::getPais() const {
    return this->pais;
}

DTDate* DTEstudiante::getFechaNacimiento() const {
    return this->fechaNacimiento;
}



// Destructor

DTEstudiante::~DTEstudiante() {
    delete this->fechaNacimiento;
}

ostream& operator<<(ostream& os, const DTEstudiante& dtEstudiante) {
    os << "Tipo: Estudiante" << endl;
    os << "Nickname: " << dtEstudiante.getNickname() << endl;
    os << "Nombre: " << dtEstudiante.getNombre() << endl;
    os << "Descripcion: " << dtEstudiante.getDescripcion() << endl;
    os << "Pais: " << dtEstudiante.getPais() << endl;
    // os << "Fecha de nacimiento: " << * dtEstudiante.getFechaNacimiento() << endl;
    return os;
}

