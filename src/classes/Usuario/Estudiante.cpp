#include "../../../include/classes/Usuario/Estudiante.h"
#include "../../../include/classes/Usuario/Usuario.h"
#include "../../../include/classes/Inscripcion.h"

#include <string>

#include "../../../include/datatypes/DTDate.h"
#include "../../../include/datatypes/DTUsuario.h"
#include "../../../include/datatypes/DTEstudiante.h"

using namespace std;

Estudiante::Estudiante() : Usuario() {}

Estudiante::Estudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, DTDate* fechaNacimiento)
    : Usuario(nickname, contrasenia, nombre, descripcion) {
    this->pais = pais;
    this->fechaNacimiento = fechaNacimiento;
    this->inscripciones = map<string, Inscripcion*>();
}

Estudiante::Estudiante(string nickname, string contrasenia, string nombre, string descripcion)
    : Usuario(nickname, contrasenia, nombre, descripcion) {
    this->pais = "";
    this->fechaNacimiento = NULL;
    this->inscripciones = map<string, Inscripcion*>();
}

Estudiante::Estudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais)
    : Usuario(nickname, contrasenia, nombre, descripcion) {
    this->pais = pais;
    this->inscripciones = map<string, Inscripcion*>();
}

string Estudiante::getPais() {
    return this->pais;
}

DTDate* Estudiante::getFechaNacimiento() {
    return this->fechaNacimiento;
}

bool Estudiante::esProfesor() {
    return false;
}

bool Estudiante::esEstudiante() {
    return true;
}

DTUsuario* Estudiante::getDT() {
    string nickname = getNickname();
    string contrasenia = getContrasenia();
    string nombre = getNombre();
    string descripcion = getDescripcion();

    return new DTEstudiante(nickname, contrasenia, nombre, descripcion, pais, fechaNacimiento);
}

set<DTDataCursoEstudiante*> Estudiante::getDTDataCursoEstudiante(){
    string nombreCurso;
    float porcentajeAvance;
    map<string, Inscripcion*> inscripciones = this->inscripciones;
    set<DTDataCursoEstudiante*> dataCursoEstudiante;
    //Recorremos inscripciones y creamos DTDataCursoEstudiante por cada una de ellas
    for(auto it = inscripciones.begin(); it != inscripciones.end(); ++it){
        nombreCurso = it->first;
        porcentajeAvance = it->second->calcPorcentajeAvance();
        //Hacer delete por cada DT creado
        dataCursoEstudiante.insert(new DTDataCursoEstudiante(nombreCurso, porcentajeAvance));
    }
    return dataCursoEstudiante;
}

void Estudiante::setPais(string pais) {
    this->pais = pais;
}

void Estudiante::setFechaNacimiento(DTDate* fechaNacimiento) {
    this->fechaNacimiento = fechaNacimiento;
}


void Estudiante::setFechaNacimiento(int dia, int mes, int anio) {
    if (fechaNacimiento == NULL) {
        fechaNacimiento = new DTDate(dia, mes, anio);
    } else {
        delete fechaNacimiento;
        fechaNacimiento = new DTDate(dia, mes, anio);
    }
}

map<string, Inscripcion*> Estudiante::getInscripciones() {
    return this->inscripciones;
}


Estudiante::~Estudiante() {
    delete fechaNacimiento;
}
