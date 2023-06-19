#include "../../include/controllers/ControladorEstadistica.h"

#include "../../include/classes/Usuario/Usuario.h"
#include "../../include/classes/Usuario/Profesor.h"
#include "../../include/classes/Usuario/Estudiante.h"
#include "../../include/classes/Curso/Curso.h"

#include "../../include/handlers/HandlerUsuario.h"
#include "../../include/handlers/HandlerCurso.h"

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stdexcept>

#include <iostream>

using namespace std;

// HandlerIdioma* colecIdiomas = HandlerIdioma::getInstancia();

HandlerUsuario* colecUsuarios = HandlerUsuario::getInstancia();

HandlerCurso* colecCursos = HandlerCurso::getInstancia();

// Inicialización de la instancia estática
ControladorEstadistica* ControladorEstadistica::instancia = NULL;

ControladorEstadistica::ControladorEstadistica() {}

IControladorEstadistica* ControladorEstadistica::getInstancia() {
    if (!instancia) {
        instancia = new ControladorEstadistica();
    }
    return instancia;
}

set<string> ControladorEstadistica::listarNicknameEstudiantes() {
    set<string> nicknames; 
    set<string> nicks;
    set<Usuario*> usuarios = colecUsuarios->obtenerUsuarios();
    set<Usuario*>::iterator it;
    for (it = usuarios.begin(); it != usuarios.end(); it++) {
        Usuario* usuario = *it;
        if (usuario->esEstudiante()) {
            nicknames.insert(usuario->getNickname());
        }
    }
    return nicknames;
}

set<DTDataCursoEstudiante*> ControladorEstadistica::listarCursosEstudiante(){
    set<DTDataCursoEstudiante*> dataCursosEstudiante;
    Usuario* usuario = colecUsuarios->obtenerUsuario(this->actual_nickname);
    //Obtenemos el estudiante
    Estudiante* estudiante = dynamic_cast<Estudiante*>(usuario);

    return estudiante->getDTDataCursoEstudiante();
}


set<string> ControladorEstadistica::listarNIcknameProfesores() {
    set<string> nicknames; 
    set<string> nicks;
    set<Usuario*> usuarios = colecUsuarios->obtenerUsuarios();
    set<Usuario*>::iterator it;
    for (it = usuarios.begin(); it != usuarios.end(); it++) {
        Usuario* usuario = *it;
        if (usuario->esProfesor()) {
            nicknames.insert(usuario->getNickname());
        }
    }
    return nicknames;
    
}

void ControladorEstadistica::seleccionarEstudiante(string nicknameEstudiante) { //TODO: Tiene que existir el profesor
    if(!(colecUsuarios->existeUsuario(nicknameEstudiante))){
        throw invalid_argument("");
    }else{
        this->actual_nickname = nicknameEstudiante;
    }
}

void ControladorEstadistica::seleccionarProfesor(string nicknameProfesor) { //TODO: Tiene que existir el profesor
    if(!(colecUsuarios->existeUsuario(nicknameProfesor))){
        throw invalid_argument("");
    }else{
        this->actual_nickname = nicknameProfesor;
    }
}

set<DTDataCursoProfesor*> ControladorEstadistica::listarCursosProfesor(){
    set<DTDataCursoProfesor*> dataCursosProfesor;
    Usuario* usuario = colecUsuarios->obtenerUsuario(this->actual_nickname);

    Profesor *profesor = dynamic_cast<Profesor*>(usuario);

    return profesor->getCursosProfesor();
} 

set<string> ControladorEstadistica::obtenerCursos() {
    HandlerCurso *h = HandlerCurso::getInstancia();
    map<string, Curso*> mapCursos = h->obtenerCursos();
    set<string> cursos;
    for(auto it = mapCursos.begin(); it != mapCursos.end(); ++it){
        cursos.insert(it->second->getNombre());
    }
    // Implementación de la función obtenerCursos
    // Código para obtener la lista de cursos disponibles
    return cursos;
}

void ControladorEstadistica::seleccionarCurso(string nombreCurso) {
    this->nombreCurso = nombreCurso;
    this->leccionesCursoActual = colecCursos->obtenerCurso(nombreCurso)->getLecciones();
}

DTDataInfoCurso* ControladorEstadistica::listarInfoCurso(){
    set<DTDataInfoCurso*> dataInfoCursos;
    Curso *curso = colecCursos->obtenerCurso(this->nombreCurso);

    return curso->getDTInfoCursos();
}

ControladorEstadistica::~ControladorEstadistica() {
    if(colecCursos != NULL){
        colecCursos->deleteInstancia();
        colecCursos = NULL;
    }
    if(colecUsuarios != NULL){
        colecUsuarios->deleteInstancia();
        colecUsuarios = NULL;
    }
}