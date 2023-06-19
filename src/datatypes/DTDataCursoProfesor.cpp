#include "../../include/datatypes/DTDataCursoProfesor.h"

#include <string>
#include <iostream>

using namespace std;

DTDataCursoProfesor::DTDataCursoProfesor(string nombreCurso, float promedioAvanceProfesor) {
    this->nombreCurso = nombreCurso;
    this->promedioAvanceProfesor = promedioAvanceProfesor;
}

string DTDataCursoProfesor::getNombreCurso() {
    return this->nombreCurso;
}

float DTDataCursoProfesor::getPromedioAvanceProfesor() {
    return this->promedioAvanceProfesor;
}

DTDataCursoProfesor::~DTDataCursoProfesor() {}

ostream& operator<<(ostream& os, const DTDataCursoProfesor& dtCursoProfesor) {
    os << "Nombre del curso: " << dtCursoProfesor.nombreCurso << endl;
    os << "Porcentaje de avance de todos los estudiantes del curso: " << dtCursoProfesor.promedioAvanceProfesor << "%" << endl;
    return os;
}