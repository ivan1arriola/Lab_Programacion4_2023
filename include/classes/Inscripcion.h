#ifndef INSCRIPCION
#define INSCRIPCION

#include <iostream>
#include <string>
#include <map>

#include "../datatypes/DTDate.h"
#include "../datatypes/DTInscripcion.h"

#include "Usuario/Estudiante.h"

#include "Curso/Ejercicio.h"

class Curso;

using namespace std;

class Inscripcion {
private:
    DTDate* fechaInscripcion;
    bool aprobado;

    Estudiante* estudiante;
    Curso* curso;

    set<Ejercicio*> ejAprobados;
    set<Ejercicio*> ejNoAprobados;
    float cantEjsAprobados;

public:

    // Constructores
    Inscripcion();
    Inscripcion(DTDate* fechaInscripcion, bool aprobado, Estudiante* estudiante, Curso* curso);
    Inscripcion(DTDate* fechaInscripcion, bool aprobado, Estudiante* estudiante, Curso* curso,set<Ejercicio*>);

    // Getters
    DTDate* getFechaInscripcion();
    bool getAprobado();
    set<Ejercicio*> getejAprobados();
    set<Ejercicio*> getejNoAprobados();
    float getcantEjAprobados();

    // Setters
    void setFechaInscripcion(DTDate* date);
    void setAprobado(bool);
    void setcantEjAprobados();

    void setejAprobado(Ejercicio*);
    void setejNoAprobado(Ejercicio*);

    void aproboEjercicio();

    // Metodos
    string obtenerNombreCurso();
    float calcPorcentajeAvance();
    float getCantEjsAprob(); 
    DTInscripcion* getDTInscripcion();

    ~Inscripcion();   

    
};

#include "Curso/Curso.h"

#endif