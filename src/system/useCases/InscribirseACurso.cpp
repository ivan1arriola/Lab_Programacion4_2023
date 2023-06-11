#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"

using namespace std;

/**
 * Nombre Inscribirse a curso
Actores Usuario
Sinopsis El caso de uso comienza cuando un usuario desea realizar una inscripción a un curso.
Para esto, el Usuario ingresa el nickname y el Sistema lista todos los cursos disponibles
para dicho estudiante. Esta lista incluye todos los cursos habilitados en los que aún no
se ha inscripto el estudiante y cuyos cursos previos han sido todos aprobados por el
estudiante. La información listada por cada curso incluye sus datos básicos, así como la
cantidad total de lecciones y de ejercicios del mismo. Finalmente, el Usuario selecciona
el curso y el Sistema genera la correspondiente inscripción.
*/

void Sistema::inscribirseACurso() {
    imprimirMensaje("Inscribirse a Curso");

    set<string> cursos = controladorCurso->listarCursosHabilitados();

    if(cursos.empty()) {
        imprimirMensaje("No hay cursos disponibles");
        imprimirMensaje("Cancelando inscripción a curso");
        return;
    }

    // Selecciona un curso de los cursos disponibles
    string curso = seleccionarElemento(cursos, "Curso");


}
