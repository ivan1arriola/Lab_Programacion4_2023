#include "../../../include/classes/Usuario/Estudiante.h"
#include "../../../include/classes/Usuario/Usuario.h"

#include <string>

#include "../../../include/datatypes/DTDate.h"

using namespace std;

// Constructor
//TODO: Elimine implementacion de constructores, hay que volverlas a hacer

// Getters

string Estudiante::getPais() {
  return this->pais;
}

DTDate* Estudiante::getFechaNacimiento() {
  return this->fechaNacimiento;
}

// Setters

void Estudiante::setPais(string pais) {
  this->pais = pais;
}

void Estudiante::setFechaNacimiento(DTDate *fechaNacimiento) {
  this->fechaNacimiento = fechaNacimiento;
}


void Estudiante::setFechaNacimiento(int dia, int mes, int anio) {
    DTDate* fechaNacimiento = new DTDate(dia, mes, anio);
    this->fechaNacimiento = fechaNacimiento;
}

// Destructor
//TODO: Elimine implementacion de destrucor, hay que volverla a hacer
