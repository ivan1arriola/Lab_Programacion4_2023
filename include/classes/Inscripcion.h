#ifndef INSCRIPCION
#define INSCRIPCION

#include <iostream>
#include <string>
#include <map>

#include "../datatypes/DTDate.h"
#include "../datatypes/DTInscripcion.h"

#include "Usuario/Estudiante.h"

class Curso;

using namespace std;

class Inscripcion {
private:
    DTDate* fechaInscripcion;
    bool aprobado;

    Estudiante* estudiante;
    Curso* curso;

public:

    // Constructores
    Inscripcion();
    Inscripcion(DTDate* fechaInscripcion, bool aprobado, Estudiante* estudiante, Curso* curso);

    // Getters
    DTDate* getFechaInscripcion();
    bool getAprobado();

    // Setters
    void setFechaInscripcion(DTDate* date);
    void setAprobado(bool);

    // Metodos
    string obtenerNombreCurso();
    float calcPorcentajeAvance();
    float getCantEjsAprob(); 
    DTInscripcion* getDTInscripcion();

    ~Inscripcion();   
    
};

#include "Curso/Curso.h"

#endif