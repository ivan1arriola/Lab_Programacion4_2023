#include "../../include/datatypes/DTDataInfoCurso.h"

#include <string>

using namespace std;

DTDataInfoCurso::DTDataInfoCurso(string nombreCurso, float promedioAvanceCurso) {
    this->nombreCurso = nombreCurso;
    this->promedioAvanceCurso = promedioAvanceCurso;
}

string DTDataInfoCurso::getNombreCurso() {
    return this->nombreCurso;
}

float DTDataInfoCurso::getPromedioAvanceCurso() {
    return this->promedioAvanceCurso;
}

DTDataInfoCurso::~DTDataInfoCurso() {}

