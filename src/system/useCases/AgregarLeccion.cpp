#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"

using namespace std;

/**
 * Nombre Agregar lección
Actores Usuario
Sinopsis El caso de uso comienza cuando se desea agregar una nueva lección a la definición de
un curso. Para ello, el Sistema lista todos los cursos no habilitados, el Usuario
selecciona uno y el Sistema solicita el nombre del tema que tratará la lección y su
objetivo. Opcionalmente, el Sistema permite también que el Usuario agregue los
ejercicios que la componen. Por cada ejercicio que se desea agregar, el Usuario ingresa
el tipo de ejercicio y la descripción. Para los ejercicios de completar palabras, el
Usuario ingresa la frase a completar, donde las palabras faltantes se representan
mediante 3 guiones, por ejemplo, “Mi --- es Juan y tengo 21 ---”, y, por otro lado, el
conjunto ordenado de palabras separados por una coma que conforman la solución (en
el caso anterior sería: “nombre”, “años”). Por otra parte, para los ejercicios de
traducción, el Usuario ingresa la frase a traducir, seguida de la frase traducida, por
ejemplo, “Soy Juan”, y su traducción, “I am Juan”. Notar que el sistema admite agregar
lecciones sin que estas tengan necesariamente ejercicios. Una vez que el Usuario
termina, el Sistema da de alta la lección con los datos ingresados al final de la lista
ordenada de lecciones y sus ejercicios, en caso de existir.
 * 
*/

void Sistema::agregarLeccion() {
    

 
        imprimirMensaje("Agregar lección");

        // Listar cursos no habilitados
        // ...
        set<string> nombresCursos = controladorCurso->listarCursosNoHabilitados();
     // Imprimir cursos disponibles
        if (nombresCursos.empty()) {
        imprimirMensaje("No hay cursos disponibles");
        return;
        }
        imprimirSet(nombresCursos, "Cursos disponibles");
        // Seleccionar curso
        // ...
         string nombreCurso = seleccionarElemento(nombresCursos, "curso");
         imprimirMensaje("Ha seleccionado el curso: " + nombreCurso);

        controladorCurso->seleccionarCurso(nombreCurso);

        cout << endl;

        // Ingresar tema
        string tema = ingresarParametro("el tema");

        espacioSimple();

        // Ingresar objetivo
        string objetivo = ingresarParametro("el objetivo");

        espacioSimple();

        // Crear lección
        Leccion leccion(tema, objetivo);

       // Agregar ejercicios (opcionalmente)
        cout << "Desea agregar ejercicios? (1. Sí, 0. No): ";
        int agregarEjercicios = ingresarOpcion(1);
        while (agregarEjercicios == 1) {
            espacioSimple();
            cout << "Tipo de ejercicio:" << endl;
            cout << "1. Completar palabras" << endl;
            cout << "2. Traducción" << endl;
            int tipoEjercicio = ingresarOpcion(2);

            espacioSimple();

            string descripcion = ingresarParametro("la descripción");

            espacioSimple();

            if (tipoEjercicio == 1) {
                string frase = ingresarParametro("la frase a completar");
                string solucion = ingresarParametro("la solución (palabras separadas por comas)");

                Ejercicio ejercicio("Completar palabras", descripcion + " - Frase: " + frase + ", Solución: " + solucion);
                leccion.crearEjercicioYAgregarlo(ejercicio);
            } else if (tipoEjercicio == 2) {
                string frase = ingresarParametro("la frase a traducir");
                string traduccion = ingresarParametro("la traducción");

                Ejercicio ejercicio("Traducción", descripcion + " - Frase: " + frase + ", Traducción: " + traduccion);
                leccion.crearEjercicioYAgregarlo(ejercicio);
            }

            espacioSimple();

            cout << "Desea agregar otro ejercicio? (1. Sí, 0. No): ";
            agregarEjercicios = ingresarOpcion(1);
        }

        espacioSimple();

        // Imprimir datos ingresados
        cout << "Datos ingresados:" << endl;
        cout << "Tema: " << leccion.tema << endl;
        cout << "Objetivo: " << leccion.objetivo << endl;
        cout << "Ejercicios:" << endl;
        for (const auto& ejercicio : leccion.ejercicios) {
            cout << "- Tipo: " << ejercicio.tipo << endl;
            cout << "  Descripción: " << ejercicio.descripcion << endl;
        }

        espacioSimple();

        // Dar de alta la lección
        // ...
        controladorCurso->agregarLeccion(leccion.tema, leccion.objetivo);
        for (const auto& ejercicio : leccion.ejercicios) {
            controladorCurso->agregarEjercicio(string nombreEjercicio, ejercicio.tipo, ejercicio.descripcion)
        }

        cout << "Lección agregada con éxito" << endl;
    

}


