#include <iostream>
#include <string>
#include <set>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"

using namespace std;

/*
Nombre: Consultar curso
Actores: Usuario
Sinopsis: El caso de uso comienza cuando se desea obtener la información de un curso. Para ello,
el Sistema lista todos los nombres de los cursos y el Usuario selecciona uno. Luego, el
Sistema muestra el nombre del curso, la descripción, la dificultad (Principiante, Medio,
Avanzado), el nombre del idioma, el nombre del profesor y si se encuentra habilitado o
no. Si posee lecciones, se mostrarán en orden, con el tema y objetivo y, si la lección
posee ejercicios, se mostrará la descripción y la información particular para cada
ejercicio. Si el curso posee inscripciones, se listará el nombre de los estudiantes y la
fecha en la que se realizó la inscripción correspondiente.
*/

void Sistema::consultarCurso() {
    imprimirMensaje("Consultar Curso");

    set<string> listaCursos = controladorCurso -> listarNombreCursos();

    if(listaCursos.empty()) {
        imprimirMensaje("No hay Cursos cargados en el sistema");
        imprimirMensaje("Cancelando operacion");
        return;
    }

    


    
}
