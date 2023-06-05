#include "../../../include/classes/Usuario/Estudiante.h"
#include "../../../include/classes/Usuario/Usuario.h"

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
}

Estudiante::Estudiante(string nickname, string contrasenia, string nombre, string descripcion)
    : Usuario(nickname, contrasenia, nombre, descripcion) {}

Estudiante::Estudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais)
    : Usuario(nickname, contrasenia, nombre, descripcion) {
    this->pais = pais;
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
    return new DTEstudiante(getNickname(), getContrasenia(), getNombre(), getDescripcion(), getPais(), getFechaNacimiento());
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

void Estudiante::enviarNotificacion(string nombreCurso, string nombreIdioma) {
    // TODO
}

Estudiante::~Estudiante() {
    delete fechaNacimiento;
}
