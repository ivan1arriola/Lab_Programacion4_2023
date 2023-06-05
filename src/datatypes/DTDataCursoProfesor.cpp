#include "../../include/datatypes/DTDataCursoProfesor.h"

#include <string>

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

