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
    imprimirMensaje("Consultar curso");

    // Obtener colección de cursos
    set<string> nombresCursos = controladorCurso->listarNombreCursos();

    // Imprimir cursos disponibles
    if (nombresCursos.empty()) {
        imprimirMensaje("No hay cursos disponibles");
        return;
    }

    imprimirSet(nombresCursos, "Cursos disponibles");

    // Seleccionar curso
    string nombreCurso = seleccionarElemento(nombresCursos, "curso");
    imprimirMensaje("Ha seleccionado el curso: " + nombreCurso);

    controladorCurso->seleccionarCurso(nombreCurso);

    cout << endl;

    // Obtener información del curso
    DTDataCurso* dtCurso = controladorCurso->mostrarDatosCurso();

    cout << *dtCurso << endl;

    cout << endl;  /**

    // Obtener lecciones del curso
    vector<dtLeccionMostrar*> lecciones = dtCurso->getLecciones();

    if (lecciones.empty()) {
        imprimirMensaje("El curso no tiene lecciones disponibles");
    } else {
        cout << "Lecciones del curso:" << endl;

        for (const auto& dtLeccionMostrar : lecciones) {
            cout << "Tema: " << dtLeccionMostrar->getTema() << endl;
            cout << "Objetivo: " << dtLeccionMostrar->getObjetivo() << endl;

            // Obtener ejercicios de la lección
            vector<DTEjercicioMostrar*> ejercicios = DataEjercicioMostrar();

            if (ejercicios.empty()) {
                imprimirMensaje("La lección no tiene ejercicios disponibles");
            } else {
                cout << "Ejercicios de la lección:" << endl;

                for (const auto& DTEjercicioMostrar : ejercicios) {
                    cout << "Descripción: " << DTEjercicioMostrar->getDescEjercicio() << endl;
                    cout << "Tipo de ejercicio: " << DTEjercicioMostrar->getTipoEjercicio() << endl;
                    cout << endl;
                }
            }

            cout << endl;
        }
    }

    // Obtener inscripciones del curso
    vector<DTInscripcion*> inscripciones = DataInscripciones();

    if (inscripciones.empty()) {
        imprimirMensaje("El curso no tiene inscripciones");
    } else {
        cout << "Inscripciones del curso:" << endl;

        for (const auto& dtInscripcion : inscripciones) {
            cout << "Estudiante: " << dtInscripcion->getEstudiante() << endl;
            cout << "Fecha de inscripción: " << dtInscripcion->getFecha() << endl;
            cout << endl;
        }
    }
*/
  
    }