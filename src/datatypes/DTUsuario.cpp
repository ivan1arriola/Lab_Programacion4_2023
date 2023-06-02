#include "../../include/datatypes/DTUsuario.h"

#include <string>

using namespace std;

DTUsuario::DTUsuario() {}

DTUsuario::DTUsuario(string nickname, string contrasenia, string nombre, string descripcion) {
    this->nickname = nickname;
    this->contrasenia = contrasenia;
    this->nombre = nombre;
    this->descripcion = descripcion;
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

