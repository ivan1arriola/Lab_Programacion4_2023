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

string DTUsuario::getNickname() const {
    return this->nickname;
}

string DTUsuario::getContrasenia() const {
    return this->contrasenia;
}

string DTUsuario::getNombre() const {
    return this->nombre;
}

string DTUsuario::getDescripcion() const {
    return this->descripcion;
}

int DTUsuario::getTipo() const {
    return this->tipo;
}


// Destructor

DTUsuario::~DTUsuario() {}
