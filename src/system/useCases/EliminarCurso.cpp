#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"
using namespace std;

/**
Nombre Eliminar curso
Actores Usuario
Sinopsis El caso de uso comienza cuando se desea eliminar un curso. Para ello, el Sistema lista
todos los nombres de los cursos y el Usuario selecciona el que desea eliminar.
Posteriormente, el Sistema elimina el curso seleccionado, así como todas sus lecciones,
ejercicios, inscripciones y registros de aprobaciones de los estudiantes vinculadas con
el curso.
*/

void Sistema::eliminarCurso() {
    imprimirMensaje("Eliminar Curso");
    set<string> f= controladorCurso->obtenerCursos(); //obtenercursos()
    imprimirMensaje("Ingrese el indice del curso a eliminar");
    imprimirOpcionesSet(f,"Cursos");
    int opcion=ingresarOpcion(f.size());
    if (opcion!=0){
        string nom=obtenerOpcion(f,opcion);
        controladorCurso->eliminarCurso(nom);
        imprimirMensaje("Curso eliminado con exito");
    }

}
