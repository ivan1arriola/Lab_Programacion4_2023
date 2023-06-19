#include "../../include/controllers/ControladorEstadistica.h"

// Inicialización de la instancia estática
ControladorEstadistica* ControladorEstadistica::instancia = nullptr;

ControladorEstadistica::ControladorEstadistica() {}

IControladorEstadistica* ControladorEstadistica::getInstancia() {
    if (!instancia) {
        instancia = new ControladorEstadistica();
    }
    return instancia;
}

set<string> ControladorEstadistica::listarNicknameEstudiantes() {
    // Implementación de la operación
    set<string> nicknames;
    // Lógica para obtener los nicknames de los estudiantes
    // Agregarlos al conjunto 'nicknames'
    return nicknames;
}

set<DTDataCursoEstudiante> ControladorEstadistica::listarCursosEstudiante(string nicknameE) {
    // Implementación de la operación
    set<DTDataCursoEstudiante> cursosEstudiante;
    // Lógica para obtener los cursos del estudiante 'nicknameE'
    // Agregarlos al conjunto 'cursosEstudiante'
    return cursosEstudiante;
}

ControladorEstadistica::~ControladorEstadistica() {
    // Liberar recursos si es necesario
    delete instancia;
}
