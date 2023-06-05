#include "../../include/datatypes/DTUsuario.h"

#include <string>
#include <iostream>

using namespace std;

DTUsuario::DTUsuario() {}

DTUsuario::DTUsuario(int tipo) {
    this->tipo = tipo;
}

DTUsuario::DTUsuario(string nickname, string contrasenia, string nombre, string descripcion, int tipo) {
    this->nickname = nickname;
    this->contrasenia = contrasenia;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->tipo = tipo;
}

// Getters

string DTUsuario::getNickname() {
    return this->nickname;
}

string DTUsuario::getContrasenia() {
    return this->contrasenia;
}

string DTUsuario::getNombre() {
    return this->nombre;
}

string DTUsuario::getDescripcion() {
    return this->descripcion;
}

// Destructor

DTUsuario::~DTUsuario() {}

ostream& operator<<(ostream& os, DTUsuario& dtUsuario) {
    dtUsuario.imprimir(os);
    return os;
}

void DTUsuario::imprimir(ostream& os) {
    os << "Nickname: " << this->getNickname() << endl;
    os << "Nombre: " << this->getNombre() << endl;
    os << "Descripcion: " << this->getDescripcion() << endl;
}

