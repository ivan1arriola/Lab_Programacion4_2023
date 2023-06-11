#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"

using namespace std;

/**
 * Nombre Habilitar curso
Actores Usuario
Sinopsis El caso de uso comienza cuando se finaliza la definición de un curso y se desea dejarlo
disponible para los estudiantes. Para ello, el Sistema lista todos los cursos no
habilitados, el Usuario selecciona uno y el sistema lo deja disponible para que los
estudiantes se puedan inscribir al mismo. Un curso se puede habilitar solo si tiene al
menos una lección y un ejercicio, y no tiene lecciones sin ejercicios.
*/

void Sistema::habilitarCurso() {
    imprimirMensaje("Habilitar Curso");
}
