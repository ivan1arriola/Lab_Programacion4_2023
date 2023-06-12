#include "../../include/classes/Inscripcion.h"
#include "../../include/datatypes/DTDate.h"

// Constructores
Inscripcion::Inscripcion() {
    fechaInscripcion = nullptr;
    aprobado = false;
    estudiante = nullptr;
    curso = nullptr;
}


Inscripcion::Inscripcion(DTDate* fechaInscripcion, bool aprobado, Estudiante* estudiante, Curso* curso) {
    this->fechaInscripcion = fechaInscripcion;
    this->aprobado = aprobado;
    this->estudiante = estudiante;
    this->curso = curso;
}

// Getters
DTDate* Inscripcion::getFechaInscripcion() {
    return fechaInscripcion;
}

bool Inscripcion::getAprobado() {
    return aprobado;
}

// Setters
void Inscripcion::setFechaInscripcion(DTDate* date) {
    fechaInscripcion = date;
}

void Inscripcion::setAprobado(bool aprobado) {
    this->aprobado = aprobado;
}

// Métodos
string Inscripcion::obtenerNombreCurso() {
    if (curso != nullptr) {
        return curso->getNombre();
    }
    return "";
}

float Inscripcion::calcPorcentajeAvance() {
    if (curso != nullptr) {
        return (getCantEjsAprob() / curso->getCantEjsTotal()) * 100.0;
    }
    return 0.0;
}

float Inscripcion::getCantEjsAprob() {
    if (curso != nullptr) {
        // Aquí debes implementar la lógica para obtener la cantidad de ejercicios aprobados
        // en función de la relación entre Inscripcion y Curso.
        // No se puede proporcionar una implementación sin conocer el diseño completo.
    }
    return 0.0;
}