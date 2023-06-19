#include "../../include/datatypes/DTDataInfoCurso.h"

#include <string>
#include <iostream>

using namespace std;

DTDataInfoCurso::DTDataInfoCurso(string nombreCurso, string descripcion, Nivel nivel, bool disponible, string nombreIdioma, float promedioAvanceCurso) {
    this->nombreCurso = nombreCurso;
    this->descripcion = descripcion;
    this->nivel = nivel;
    this->disponible = disponible;
    this->promedioAvanceCurso = promedioAvanceCurso;
    this->nombreIdioma = nombreIdioma;
    // this->nombreProfesor = nombreProfesor;
}

string DTDataInfoCurso::getNombreCurso() {
    return this->nombreCurso;
}

float DTDataInfoCurso::getPromedioAvanceCurso() {
    return this->promedioAvanceCurso;
}

string DTDataInfoCurso::getDescripcion() {
return descripcion;
}

string DTDataInfoCurso::getNivel() {
    if(nivel == 0){
        return "Principiante";
    }else if(nivel == 1){
        return "Medio";
    }else{
        return "Avanzado";
    }
}

string DTDataInfoCurso::getDisponible() {
    if(disponible){
        return "Disponible";
    }else{
        return "No disponible";
    }
}

string DTDataInfoCurso::getNombreIdioma() {
return nombreIdioma;
}

// string DTDataInfoCurso::getNombreProfesor() {
// return nombreProfesor;
// }

DTDataInfoCurso::~DTDataInfoCurso() {}

ostream& operator<<(ostream& os, const DTDataInfoCurso& dtCurso) {
    os << "Datos del Curso:" << endl;
    os << "Nombre: " << dtCurso.nombreCurso << endl;
    os << "Descripcion: " << dtCurso.descripcion << endl;
    if(dtCurso.nivel == 0){
        os << "Nivel: " << "Principiante" << endl;
    }else if(dtCurso.nivel == 1){
        os << "Nivel: " << "Medio" << endl;
    }else{
        os << "Nivel: " << "Avanzado" << endl;
    }
    if(dtCurso.disponible){
        os << "Disponible: " << "Sí" << endl;
    }else{
        os << "Disponible: " << "No" << endl;
    }
    os << "Idioma: " << dtCurso.nombreIdioma << endl;
    // os << "Profesor: " << dtCurso.nombreProfesor << endl;
    os << "Promedio de avance total del curso: " << dtCurso.promedioAvanceCurso << "%" << endl;
    return os;
}

