#include "../../include/classes/Idioma.h"

#include <string>

#include "../../include/interfaces/ISuscriptor.h"

using namespace std;

// Constructor

Idioma::Idioma() {}

Idioma::Idioma(string nombre) {
  this->nombre = nombre;
}

// Getters

string Idioma::getNombre() {
  return this->nombre;
}

// Operaciones

void Idioma::agregarSuscriptor(ISuscriptor suscriptor) {
  this->suscriptores.insert(suscriptor);
}

//void Idioma::eliminarSuscriptor(string nickname);



void Idioma::notificarSuscriptores() {
}

bool Idioma::contieneSuscriptor(string nickname) {
  
  return false;
}

set<string> Idioma::getIdiomasProfesor() {
  set<string> idiomasProfesor;
  
  return idiomasProfesor;
}

// Destructor

Idioma::~Idioma() {
  this->suscriptores.clear();
}

bool Idioma::operator==(const Idioma& otro) {
  return this->nombre == otro.getNombre();
}