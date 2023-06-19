#include "../../../include/classes/Usuario/Profesor.h"
#include "../../../include/classes/Inscripcion.h"
#include "../../../include/classes/Curso/Curso.h"

#include <string>

#include "../../../include/classes/Usuario/Usuario.h"

#include "../../../include/datatypes/DTUsuario.h"
#include "../../../include/datatypes/DTProfesor.h"
#include "../../../include/datatypes/DTDataCursoProfesor.h"

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
  set<string> idiomas;
  for(Idioma* i : this->getIdiomas()){
    idiomas.insert(i->getNombre());
  }
  DTUsuario* dtUsuario = new DTProfesor(this->getNickname(), this->getContrasenia(), this->getNombre(), this->getDescripcion(), this->getInstituto(), idiomas);
  return dtUsuario;
}

// Setters

void Profesor::setInstituto(string instituto) {
  this->instituto = instituto;
}

void Profesor::agregarAIdiomasDeProfesor(Idioma *idioma){
  idiomasDeProfesor.insert(idioma);
}

void Profesor::agregarACursosDeProfesor(Curso *curso){
  cursosCreados.insert(curso);
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

set<Curso*> Profesor::getCursosCreados(){
  return this->cursosCreados;
}

set<DTDataCursoProfesor*> Profesor::getCursosProfesor() {
  string nombreCurso;
  float porcentajeAvance = 0;
  set<Curso*> cursos = cursosCreados;
  int cantEstudiantes;
  set<DTDataCursoProfesor*> cursosProfesor;
  // DTDataCursoProfesor* dt;
  //Recorremos los cursos para obtener sus inscripciones y porcentaje de avance total
  for(Curso* curso : cursos){
    map<string, Inscripcion*> inscripciones = curso->getInscripciones();
    nombreCurso = curso->getNombre(); 
    //Hay que recorrer las inscripciones y obtener el promedio de avance
    //de cada estudiante 
    for(auto it = inscripciones.begin(); it != inscripciones.end(); ++it){
      porcentajeAvance = porcentajeAvance + it->second->calcPorcentajeAvance();
    }
    cantEstudiantes = inscripciones.size();
    if(cantEstudiantes != 0){
      porcentajeAvance = porcentajeAvance/cantEstudiantes;
    }
    
    // dt = new DTDataCursoProfesor(nombreCurso, porcentajeAvance);
    cursosProfesor.insert(new DTDataCursoProfesor(nombreCurso, porcentajeAvance));
  }
  
  return cursosProfesor;
}


set<Idioma*> Profesor::getIdiomas() {
  return this->idiomasDeProfesor;
}

Profesor::~Profesor() {
    // Destruye todos las notificaciones recibidas
}

