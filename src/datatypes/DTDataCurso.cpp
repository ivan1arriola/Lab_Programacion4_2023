#include "../../include/datatypes/DTDataCurso.h"

#include <string>
#include <iostream>

DTDataCurso::DTDataCurso()
{
    // Constructor por defecto
}

DTDataCurso::DTDataCurso(string nombre, string descripcion, Nivel nivel, bool disponible, string nombreIdioma, string nombreProfesor)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->nivel = nivel;
    this->disponible = disponible;
    this->nombreIdioma = nombreIdioma;
    this->nombreProfesor = nombreProfesor;
}

DTDataCurso::DTDataCurso(string nombre, string descripcion, Nivel nivel, bool disponible, string nombreIdioma, string nombreProfesor, vector<DTDataLeccion *> lecciones)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->nivel = nivel;
    this->disponible = disponible;
    this->nombreIdioma = nombreIdioma;
    this->nombreProfesor = nombreProfesor;
    this->lecciones = lecciones;
}

string DTDataCurso::getNombre()
{
    return nombre;
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

string DTDataCurso::getNombreIdioma()
{
    return nombreIdioma;
}

string DTDataCurso::getNombreProfesor()
{
    return nombreProfesor;
}


DTDataCurso::~DTDataCurso()
{
    // Destructor
    for (long unsigned int i = 0; i < lecciones.size(); i++)
    {
        delete lecciones[i];
    }
}

ostream &operator<<(ostream &os, const DTDataCurso &dtCurso)
{
    os << "Datos del Curso:" << endl;
    os << "----------------" << endl;
    os << "Nombre: " << dtCurso.nombre << endl;
    os << "Descripcion: " << dtCurso.descripcion << endl;
    if (dtCurso.nivel == 0)
    {
        os << "Nivel: "
           << "Principiante" << endl;
    }
    else if (dtCurso.nivel == 1)
    {
        os << "Nivel: "
           << "Medio" << endl;
    }
    else
    {
        os << "Nivel: "
           << "Avanzado" << endl;
    }
    if (dtCurso.disponible)
    {
        os << "Disponible: "
           << "Sí" << endl;
    }
    else
    {
        os << "Disponible: "
           << "No" << endl;
    }
    os << "Idioma: " << dtCurso.nombreIdioma << endl;
    os << "Profesor: " << dtCurso.nombreProfesor << endl;

    os << endl;

    if (dtCurso.lecciones.size() > 0)
    {
        os << "Lecciones del Curso:" << endl;
        for (long unsigned int i = 0; i < dtCurso.lecciones.size(); i++)
        {
            os << "     " << "Leccion " << i+1 << ":" << endl;
            os << *dtCurso.lecciones[i] << endl;
        }
    } else {
        os << "     " << "No hay lecciones en este curso." << endl;
    }
    return os;
}
