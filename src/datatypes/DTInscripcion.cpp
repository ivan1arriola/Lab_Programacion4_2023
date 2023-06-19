#include "../../include/datatypes/DTInscripcion.h"

#include <string>
#include <iostream>

using namespace std;

DTInscripcion::DTInscripcion(){}

DTInscripcion::DTInscripcion(string nicknameEstudiante, DTDate *fechaInscripcion){
  this->nicknameEstudiante = nicknameEstudiante;
  this->fechaInscripcion = fechaInscripcion;  
}

string DTInscripcion::getNicknameEstudiante(){
    return nicknameEstudiante;
}

DTDate* DTInscripcion::getFechaInscripcion(){
    return fechaInscripcion;
}

DTInscripcion::~DTInscripcion(){}

ostream& operator<<(ostream& os, const DTInscripcion& dtInscripcion){
    os << "Nombre del estudiante: " << dtInscripcion.nicknameEstudiante << endl;
    os << "Fecha de inscripción al curso: " << dtInscripcion.fechaInscripcion->getDay() << "/" << dtInscripcion.fechaInscripcion->getMonth() << "/" << dtInscripcion.fechaInscripcion->getYear() << endl;
    return os;
}