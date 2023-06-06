#include "../../include/controllers/ControladorCurso.h"

#include <string>

using namespace std;

ControladorCurso* ControladorCurso::instancia = NULL;



ControladorCurso::ControladorCurso() {
    // Implementación del constructor por defecto
}

ControladorCurso::~ControladorCurso() {
    // Implementación del destructor
}

IControladorCurso* ControladorCurso::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorCurso();
    return instancia;
}


set<string> ControladorCurso::listarCursosHabilitados() {
    set<string> cursos;
    // Implementación de la función listarCursosHabilitados
    // Código para obtener la lista de cursos habilitados
    return cursos;
}

void ControladorCurso::seleccionarIdioma(string nombreIdioma) {
    this->nombreIdioma = nombreIdioma;
}

void ControladorCurso::seleccionarCurso(string nombreCurso) {
    this->nombreCurso = nombreCurso;
}

void ControladorCurso::altaCurso(bool disponible) {
    // Implementación de la función altaCurso
    // Código para dar de alta un nuevo curso con los parámetros proporcionados
}

set<string> ControladorCurso::obtenerCursos() {
    set<string> cursos;
    // Implementación de la función obtenerCursos
    // Código para obtener la lista de cursos disponibles
    return cursos;
}

string ControladorCurso::getNombreCurso() {
    return nombreCurso;
}

set<string> ControladorCurso::getDataCurso() {
    set<string> dataCurso;
    // Implementación de la función getDataCurso
    // Código para obtener los datos del curso seleccionado
    return dataCurso;
}

string ControladorCurso::getNickProfesor() {
    // Implementación de la función getNickProfesor
    string nickProfesor;
    // Código para obtener el nick del profesor del curso seleccionado
    return nickProfesor;
}

set<string> ControladorCurso::getNombresCursosPrevios() {
    set<string> cursosPrevios;
    // Implementación de la función getNombresCursosPrevios
    // Código para obtener los nombres de los cursos previos del curso seleccionado
    return cursosPrevios;
}

set<DTDataLeccion> ControladorCurso::getLecciones() {
    set<DTDataLeccion> lecciones;
    // Implementación de la función getLecciones
    // Código para obtener las lecciones del curso seleccionado
    return lecciones;
}

void ControladorCurso::eliminarCurso(string nombre) {
    // Implementación de la función eliminarCurso
    // Código para eliminar el curso con el nombre proporcionado
}

void ControladorCurso::agregarLeccion(string tema, string objetivo) {
    // Implementación de la función agregarLeccion
    // Código para agregar una nueva lección al curso seleccionado con los parámetros proporcionados
}

void ControladorCurso::agregarEjercicio(string tipoEjercicio, string descEjercicio) {
    // Implementación de la función agregarEjercicio
    // Código para agregar un nuevo ejercicio a la lección actual con los parámetros proporcionados
}

void ControladorCurso::ingresarNicknameEstudiante(string nomEstudiante) {
    // Implementación de la función ingresarNicknameEstudiante
    // Código para ingresar el nickname del estudiante para realizar ejercicios
}

void ControladorCurso::ingresarDatosCurso(string nombre, string desc, string dificultad) {
    // Implementación de la función ingresarDatosCurso
    // Código para ingresar los datos del nuevo curso a crear
}

set<string> ControladorCurso::listarCursosInscrip() {
    set<string> cursosInscrip;
    // Implementación de la función listarCursosInscrip
    // Código para obtener la lista de cursos disponibles para inscripción
    return cursosInscrip;
}

set<string> ControladorCurso::mostrarCursosNoAprobados() {
    set<string> cursosNoAprobados;
    // Implementación de la función mostrarCursosNoAprobados
    // Código para obtener la lista de cursos no aprobados del estudiante
    return cursosNoAprobados;
}

set<string> ControladorCurso::mostrarEjerciciosNoAprobados() {
    set<string> ejerciciosNoAprobados;
    // Implementación de la función mostrarEjerciciosNoAprobados
    // Código para obtener la lista de ejercicios no aprobados del estudiante
    return ejerciciosNoAprobados;
}

DTEjercicio ControladorCurso::seleccionarEjercicio(string nombreEjercicio) {
    // Implementación de la función seleccionarEjercicio
    // Código para obtener los datos del ejercicio seleccionado por su nombre
    return DTEjercicio();
}

void ControladorCurso::ingresarSolucionCompletar(set<string> solC) {
    // Implementación de la función ingresarSolucionCompletar
    // Código para ingresar la solución del ejercicio de completar en el Controlador de Ejercicio
}

void ControladorCurso::ingresarSolucionTraducir(string solT) {
    // Implementación de la función ingresarSolucionTraducir
    // Código para ingresar la solución del ejercicio de traducción en el Controlador de Ejercicio
}

void ControladorCurso::marcarEjercicioAprobado() {
    // Implementación de la función marcarEjercicioAprobado
    // Código para marcar el ejercicio actual como aprobado en el Controlador de Ejercicio
}

void ControladorCurso::marcarEjercicioNoAprobado() {
    // Implementación de la función marcarEjercicioNoAprobado
    // Código para marcar el ejercicio actual como no aprobado en el Controlador de Ejercicio
}