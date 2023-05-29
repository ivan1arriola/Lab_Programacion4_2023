#include "../../../include/classes/UsuarioClasses/Usuario.h"

#include <set>
#include <string>
#include <vector>

#include "../../../include/datatypes/DTNotificacion.h"
#include "../../../include/datatypes/DTDataCursoProfesor.h"

// Constructor

Usuario::Usuario(string nickname, string contrasenia, string nombre, string descripcion) {
  this->nickname = nickname;
  this->contrasenia = contrasenia;
  this->nombre = nombre;
  this->descripcion = descripcion;
}

// Getters

string Usuario::getNickname() {
  return this->nickname;
}

string Usuario::getContrasenia() {
  return this->contrasenia;
}

string Usuario::getNombre() {
  return this->nombre;
}

string Usuario::getDescripcion() {
  return this->descripcion;
}

vector<DTNotificacion> Usuario::getNotificacionesRecibidas() {
  return this->notificacionesRecibidas;
}

// Setters

void Usuario::setNickname(string nickname) {
  this->nickname = nickname;
}

void Usuario::setContrasenia(string contrasenia) {
  this->contrasenia = contrasenia;
}

void Usuario::setNombre(string nombre) {
  this->nombre = nombre;
}

void Usuario::setDescripcion(string descripcion) {
  this->descripcion = descripcion;
}

// Operaciones

void Usuario::agregarNotificacion(DTNotificacion notificacion) {
  this->notificacionesRecibidas.push_back(notificacion);
}

void Usuario::enviarNotificacion(string nombreCurso, string nombreIdioma) {
  DTNotificacion notificacion = DTNotificacion(nombreCurso, nombreIdioma);
  this->agregarNotificacion(notificacion);
}

void Usuario::eliminarNotificacionesRecibidas() {
  this->notificacionesRecibidas.clear();
}

// Destructor

Usuario::~Usuario() {

    // Llama al destructor de cada elemento del vector notificacionesRecibidas
    for (vector<DTNotificacion>::iterator it = this->notificacionesRecibidas.begin(); it != this->notificacionesRecibidas.end(); ++it) {
        it->~DTNotificacion();
    }

}

