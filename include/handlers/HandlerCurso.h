#ifndef HANDLERCURSO
#define HANDLERCURSO

#include <map>
#include <string>

#include "../classes/Curso/Curso.h"

using namespace std;

class HandlerCurso {
private:
    map<string, Curso*> cursos; // Colección de punteros a Curso
    HandlerCurso();
    
    static HandlerCurso* instancia;

    // Destructor
    ~HandlerCurso();

public:
    static HandlerCurso* getInstancia();
    static void deleteInstancia();

    // Agregar
    void agregarCurso(Curso* curso);

    // Obtener
    Curso* obtenerCurso(string nombre);
    map<string, Curso*> obtenerCursos();

    // Consultar
    bool existeCurso(string nombre);
    bool existeCurso(Curso* curso);

    // Eliminar
    void eliminarCurso(string nombre);
    void eliminarCurso(Curso* curso);
};

#endif
