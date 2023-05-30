#include "../../../include/classes/Usuario/Estudiante.h"

#include <string>

#include "../../../include/datatypes/DTDate.h"

using namespace std;

// Constructor

Estudiante::Estudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, DTDate fechaNacimiento) : Usuario(nickname, contrasenia, nombre, descripcion) {
  this->pais = pais;
  this->fechaNacimiento = fechaNacimiento;
}

Estudiante::Estudiante(string nickname, string contrasenia, string nombre, string descripcion) : Usuario(nickname, contrasenia, nombre, descripcion) {
  this->pais = "";
  this->fechaNacimiento = DTDate();
}

// Getters

string Estudiante::getPais() {
  return this->pais;
}

DTDate Estudiante::getFechaNacimiento() {
  return this->fechaNacimiento;
}

// Setters

void Estudiante::setPais(string pais) {
  this->pais = pais;
}

void Estudiante::setFechaNacimiento(DTDate fechaNacimiento) {
  this->fechaNacimiento = fechaNacimiento;
}


void Estudiante::setFechaNacimiento(int dia, int mes, int anio) {
    DTDate fechaNacimiento = DTDate(dia, mes, anio);
    this->fechaNacimiento = fechaNacimiento;
}

// Destructor

Estudiante::~Estudiante() {
}
