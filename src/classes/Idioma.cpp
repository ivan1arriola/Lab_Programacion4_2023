/*
#ifndef IDIOMA
#define IDIOMA

#include <string>
#include <set>
#include "../interfaces/ISuscriptor.h"

using namespace std;

class Idioma {
    private:
        string nombre;
    public:
        Idioma() {};
        string getNombre();
        ~Idioma() {}

        void agregarSuscriptor(ISuscriptor suscriptor);
        void eliminarSuscriptor(string nickname);
        void notificarSuscriptores();

        bool contieneSuscriptor(string nickname);
        set<string> getIdiomasProfesor();

};

#endif
*/

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

void 

void Idioma::notificarSuscriptores() {
  for (set<ISuscriptor>::iterator it = this->suscriptores.begin(); it != this->suscriptores.end(); ++it) {
    it->enviarNotificacion(this->nombre);
  }
}

// Queries

bool Idioma::contieneSuscriptor(string nickname) {
  for (set<ISuscriptor>::iterator it = this->suscriptores.begin(); it != this->suscriptores.end(); ++it) {
    if (it->getNickname() == nickname) {
      return true;
    }
  }
  return false;
}

set<string> Idioma::getIdiomasProfesor() {
  set<string> idiomas;
  for (set<ISuscriptor>::iterator it = this->suscriptores.begin(); it != this->suscriptores.end(); ++it) {
    idiomas.insert(it->getNickname());
  }
  return idiomas;
}

// Destructor

Idioma::~Idioma() {
  this->suscriptores.clear();
}

