/*#ifndef PROFESOR
#define PROFESOR

#include <string>
#include <set>

using namespace std;

#include "Usuario.h"

class Profesor : public Usuario {
    private:
        string instituto;
    public:
        Profesor();
        Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto);

        // Getters
        string getInstituto();
        bool esProfesor();
        bool esEstudiante();

        // Setters
        void setInstituto(string instituto);

        // Operaciones
        void enviarNotificacion(string nombreCurso, string nombreIdioma);
        set<string> obtenerIdiomas();
        void agregarAIdiomasDeProfesor();
        set<DTDataCursoProfesor> getCursosProfesor();


        ~Profesor();
};

#endif*/

#include "../../../include/classes/Usuario/Profesor.h"

#include <string>

#include "../../../include/classes/Usuario/Usuario.h"

using namespace std;

// Constructor

Profesor::Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto) : Usuario(nickname, contrasenia, nombre, descripcion) {
  this->instituto = instituto;
}

// Getters

string Profesor::getInstituto() {
  return this->instituto;
}

// Setters

void Profesor::setInstituto(string instituto) {
  this->instituto = instituto;
}

// Operaciones

set<string> Profesor::obtenerIdiomas() {
  set<string> idiomas;
  idiomas.insert(this->getDescripcion());
  return idiomas;
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

