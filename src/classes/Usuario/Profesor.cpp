#include "../../../include/classes/Usuario/Profesor.h"

#include <string>

#include "../../../include/classes/Usuario/Usuario.h"

#include "../../../include/datatypes/DTUsuario.h"
#include "../../../include/datatypes/DTProfesor.h"

using namespace std;

// Constructor

Profesor::Profesor() : Usuario() {
  this->instituto = "";
}

Profesor::Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto) : Usuario(nickname, contrasenia, nombre, descripcion) {
  this->instituto = instituto;
}

Profesor::Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto, set<Idioma*> idiomasDeProfesor) : Usuario(nickname, contrasenia, nombre, descripcion) {
  this->instituto = instituto;
  this->idiomasDeProfesor = idiomasDeProfesor;
}

// Getters

string Profesor::getInstituto() {
  return this->instituto;
}

DTUsuario* Profesor::getDT() {
  DTUsuario* dtUsuario = new DTProfesor(this->getNickname(), this->getContrasenia(), this->getNombre(), this->getDescripcion(), this->getInstituto());
  return dtUsuario;
}

// Setters

void Profesor::setInstituto(string instituto) {
  this->instituto = instituto;
}

// Operaciones

set<string> Profesor::obtenerIdiomas() {
  set<string> nombresIdiomas;
  for (set<Idioma*>::iterator it = this->idiomasDeProfesor.begin(); it != this->idiomasDeProfesor.end(); it++) {
    nombresIdiomas.insert((*it)->getNombre());
  }
  return nombresIdiomas;
}

bool Profesor::esProfesor() {
  return true;
}

bool Profesor::esEstudiante() {
  return false;
}

set<DTDataCursoProfesor> Profesor::getCursosProfesor() {
  set<DTDataCursoProfesor> cursosProfesor;
  return cursosProfesor;
}

void Profesor::enviarNotificacion(string nombreCurso, string nombreIdioma){
//TODO: Sin implementar
}

Profesor::~Profesor() {
    // Destruye todos las notificaciones recibidas
}

