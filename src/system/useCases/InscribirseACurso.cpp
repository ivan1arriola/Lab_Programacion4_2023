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
    
    //Se ingresa el nickname del estudiante que se inscribirá
    string nicknameE = ingresarParametro("su nickname");
    try {
        controladorCurso->ingresarNicknameEstudiante(nicknameE);
    } catch (invalid_argument &e){
        cancelarOperacion(e.what(), "Inscribirse a Curso");
        return;
    }

    //Se busca la lista de cursos habilitados en general
    set<string> cursos = controladorCurso->listarCursosHabilitados();

    if(cursos.empty()) {
        cancelarOperacion("No hay cursos disponibles", "Inscribirse a Curso");
        return;
    }

    //Devuelve los cursos disponibles para realizar la inscripción
    vector<DTDataCursoAInscribir*> cursosDispEst = controladorCurso->obtenerCursosDisponibles(cursos);

    //Se imprimen los cursos disponibles y luego se selecciona la opcion correspondiente al curso 
    if (cursosDispEst.empty()) {
        cancelarOperacion("No hay cursos disponibles", "Inscribirse a Curso");
        return;
    }

    int i = 1;
    imprimirMensaje("0- Cancelar");
    for (const auto& curso: cursosDispEst) {
        cout << i << " - " << curso->getNombre() << endl;
        espacioSimple();
        cout << (*curso) << endl;
        espacioSimple();
        ++i;
    }    
    espacioSimple();
    int op = ingresarOpcion(i-1);
    if (op == 0){
        imprimirMensaje("Cancelando operación");
        return;
    }

    //Se recuerda el nombre del curso seleccionado para la inscripción
    string nomCursoActual = cursosDispEst[op-1]->getNombre();
    controladorCurso->seleccionarCurso(nomCursoActual);

    //Pedir y guardar fecha de inscripción
    imprimirMensaje("Ingrese la fecha de inscripción con el siguiente formato (dd mm aaaa):");
    int dia, mes, anio;
    cin >> dia >> mes >> anio;
    DTDate* fechaInscripcion = new DTDate(dia, mes, anio);

    //Crea la inscripcion
    //Se crea link entre estudiante - inscripcion e inscripcion - curso
    controladorCurso->realizarInscripcion(fechaInscripcion);
    
    imprimirMensaje("Inscripción realizada con éxito");
}
