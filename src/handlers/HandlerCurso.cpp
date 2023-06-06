#include "../../include/handlers/HandlerCurso.h"

#include <map>
#include <set>
#include <string>
#include <stdexcept>
#include <iostream>

#include "../../include/classes/Curso/Curso.h"

HandlerCurso* HandlerCurso::instancia = nullptr;

HandlerCurso::HandlerCurso() {}

HandlerCurso::~HandlerCurso() {
    // Liberar la memoria de todos los cursos
    for (auto const& pair : cursos) {
        delete pair.second;
    }
}

HandlerCurso* HandlerCurso::getInstancia() {
    if (instancia == nullptr) {
        instancia = new HandlerCurso();
    }
    return instancia;
}

void HandlerCurso::deleteInstancia() {
    delete instancia;
    instancia = nullptr;
}

void HandlerCurso::agregarCurso(Curso* curso) {
    if (curso != nullptr) {
        cursos[curso->getNombre()] = curso;
    }
}

Curso* HandlerCurso::obtenerCurso(string nombre) {
    auto it = cursos.find(nombre);
    if (it != cursos.end()) {
        return it->second;
    }
    return nullptr;
}

map<string, Curso*> HandlerCurso::obtenerCursos() {
    return cursos;
}

bool HandlerCurso::existeCurso(string nombre) {
    return cursos.find(nombre) != cursos.end();
}

bool HandlerCurso::existeCurso(Curso* curso) {
    if (curso != nullptr) {
        auto it = cursos.find(curso->getNombre());
        return it != cursos.end() && it->second == curso;
    }
    return false;
}

void HandlerCurso::eliminarCurso(string nombre) {
    auto it = cursos.find(nombre);
    if (it != cursos.end()) {
        delete it->second;
        cursos.erase(it);
    }
}

void HandlerCurso::eliminarCurso(Curso* curso) {
    if (curso != nullptr) {
        eliminarCurso(curso->getNombre());
    }
}
