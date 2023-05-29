#include "../../include/datatypes/DTDataCursoEstudiante.h"

#include <string>

using namespace std;

DTDataCursoEstudiante::DTDataCursoEstudiante(string nombreCurso, float porcentajeAvanceEstudiante) {
    this->nombreCurso = nombreCurso;
    this->porcentajeAvanceEstudiante = porcentajeAvanceEstudiante;
}

string DTDataCursoEstudiante::getNombreCurso() {
    return this->nombreCurso;
}

float DTDataCursoEstudiante::getPorcentajeAvanceEstudiante() {
    return this->porcentajeAvanceEstudiante;
}

DTDataCursoEstudiante::~DTDataCursoEstudiante() {}

