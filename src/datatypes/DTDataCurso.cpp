#include "../../include/datatypes/DTDataCurso.h"

#include <string>
#include <iostream>

DTDataCurso::DTDataCurso() {
// Constructor por defecto
}

DTDataCurso::DTDataCurso(string nombre, string descripcion, Nivel nivel, bool disponible, string nombreIdioma, string nombreProfesor) {
this->nombre = nombre;
this->descripcion = descripcion;
this->nivel = nivel;
this->disponible = disponible;
this->nombreIdioma = nombreIdioma;
this->nombreProfesor = nombreProfesor;
}

string DTDataCurso::getNombre() {
return nombre;
}

string DTDataCurso::getDescripcion() {
return descripcion;
}

string DTDataCurso::getNivel() {
    if(nivel ==0){
        return "Principiante";
    }else if(nivel ==1){
        return "Medio";
    }else{
        return "Avanzado";
    }
}

string DTDataCurso::getDisponible() {
    if(disponible){
        return "Disponible";
    }else{
        return "No disponible";
    }
}

string DTDataCurso::getNombreIdioma() {
return nombreIdioma;
}

string DTDataCurso::getNombreProfesor() {
return nombreProfesor;
}

DTDataCurso::~DTDataCurso() {
    //Destruye Lecciones
    // for (int i = 0; i < lecciones.size(); i++) {
    //     delete lecciones[i];
    // }
}

ostream& operator<<(ostream& os, const DTDataCurso& dtCurso) {
    os << "Datos del Curso:" << endl;
    os << "Nombre: " << dtCurso.nombre << endl;
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
    os << "Profesor: " << dtCurso.nombreProfesor << endl;
    return os;
}
