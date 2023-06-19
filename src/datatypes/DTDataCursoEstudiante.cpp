#include "../../include/datatypes/DTDataCursoEstudiante.h"

#include <string>
#include <iostream>

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

ostream& operator<<(ostream& os, const DTDataCursoEstudiante& dtDataCursoEstudiante) {
    os << "Nombre del curso: " << dtDataCursoEstudiante.nombreCurso << endl;
    os << "Porcentaje de avance en el curso: " << dtDataCursoEstudiante.porcentajeAvanceEstudiante << "%" << endl;
    return os;
}