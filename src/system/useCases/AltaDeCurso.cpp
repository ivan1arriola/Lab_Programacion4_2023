#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"

using namespace std;

typedef unsigned long int nat;


/*Nombre Alta de curso
Actores Usuario
Sinopsis El caso de uso comienza cuando un usuario desea dar de alta un nuevo curso en el
sistema. Para ello, el Sistema lista los nicknames de los profesores registrados y el
Usuario selecciona al que dictará el curso. Luego, el Usuario ingresa el nombre del
curso, la descripción y la dificultad (Principiante, Medio, Avanzado). A continuación,
el Sistema lista los nombres de los idiomas en los que se especializa el profesor y el
Usuario selecciona el idioma en el que enseñará el curso. Adicionalmente, el Sistema
pregunta si para inscribirse al curso se requerirá la aprobación de cursos previos. En
caso afirmativo, el Sistema lista los nombres de todos los cursos habilitados y el
Usuario selecciona aquellos que serán requeridos como previos. A continuación, el
Sistema pregunta al Usuario si desea agregar lecciones. En caso de que así sea, el
Usuario ingresa las lecciones en el orden que deberán ser realizadas por un estudiante.
Por cada lección que se desea agregar, el Usuario ingresa el nombre del tema que
tratará la lección y su objetivo. Opcionalmente, para cada lección, el sistema permite
también que el Usuario agregue los ejercicios que la componen. Por cada ejercicio que
se desea agregar, el Usuario ingresa el tipo de ejercicio y la descripción. Para los
ejercicios de completar palabras, el Usuario ingresa la frase a completar, donde las
palabras faltantes se representan mediante 3 guiones, por ejemplo, “Mi --- es Juan y
tengo 21 ---”, y, por otro lado, el conjunto ordenado de palabras separados por una
coma que conforman la solución (en el caso anterior sería: “nombre”, “años”). Por otra
parte, para los ejercicios de traducción, el Usuario ingresa la frase a traducir, seguida de
la frase traducida, por ejemplo, “Soy Juan”, y su traducción, “I am Juan”. Estos pasos
se repiten cada vez que el Usuario desea agregar una nueva lección junto a sus
ejercicios. Notar que el sistema admite agregar lecciones sin que estas tengan
necesariamente ejercicios. Una vez que el Usuario termina, el Sistema da de alta el
nuevo curso con los datos ingresados y sus lecciones y ejercicios, en caso de existir,
dejándolo no disponible para los estudiantes hasta tanto no se ejecute el caso de uso
“Habilitar curso”.*/

void Sistema::altaDeCurso()
{
    try
    {

        imprimirMensaje("Alta de Curso");

        set<string> profesores = controladorUsuario->listarNIcknameProfesores();

        if (profesores.empty()) throw invalid_argument("No hay profesores registrados");

        string nicknameProfesor = seleccionarElemento(profesores, "profesor");

        if (nicknameProfesor == "") throw invalid_argument("No se ha seleccionado un profesor");

        string nombreCurso = ingresarParametro("nombre del curso");

        if (handlerCurso->existeCurso(nombreCurso)) throw invalid_argument("Ya existe un curso con ese nombre");

        string descripcionCurso = ingresarParametro("descripcion del curso");

        Nivel dificultad = ingresarNivel();

        controladorCurso->ingresarDatosCurso(nombreCurso, descripcionCurso, dificultad, nicknameProfesor);

        set<string> idiomasDeProfesor = controladorUsuario->listarNombresIdiomasDeProfesor(nicknameProfesor);

        if (idiomasDeProfesor.size() == 0)
        {
            throw invalid_argument("El profesor no tiene idiomas registrados");
        }

        string idiomaCurso = seleccionarElemento(idiomasDeProfesor, "idioma");

        if (idiomaCurso == "")
        {
            throw invalid_argument("No se ha seleccionado un idioma");
        }

        controladorCurso->seleccionarIdioma(idiomaCurso);
        imprimirMensaje("Seleccionó el idioma: " + idiomaCurso);

        bool deseaAgregarPrevios = ingresarBooleano("¿Desea agregar cursos previos?");

        set<string> cursosPrevios = set<string>();

        set<string> cursosDisponibles = controladorCurso->listarCursosHabilitados();

        while (deseaAgregarPrevios && cursosDisponibles.size() > 0)
        {
            string cursoPrev = seleccionarElemento(cursosDisponibles, "curso previo");

            if (cursoPrev == "")
                imprimirMensaje("No se ha seleccionado un curso");
            else
            {
                cursosPrevios.insert(cursoPrev);
                imprimirMensaje("Agregó el curso previo: " + cursoPrev);
                cursosDisponibles.erase(cursoPrev);
            }
            deseaAgregarPrevios = ingresarBooleano("¿Desea seguir agregando cursos previos?");
        };

        if (cursosDisponibles.size() == 0)
        {
            imprimirMensaje("No hay mas cursos disponibles para agregar");
        };

        imprimirSet(cursosPrevios, "Cursos previos seleccionados");

        for (string cursoPrev : cursosPrevios)
        {
            controladorCurso->agregarCursoPrevio(cursoPrev);
        }

        bool deseaAgregarLecciones = ingresarBooleano("¿Desea agregar lecciones?");

        while (deseaAgregarLecciones) {
            string tema = ingresarParametro("el tema de la lección") ;
            string objetivo = ingresarParametro("el objetivo de la lección") ;
            bool deseaAgregarEjercicio = ingresarBooleano("¿Desea agregar un Ejercicio a la Leccion?") ;

            while (deseaAgregarEjercicio) {
                string nombreEjercicio = ingresarParametro("el nombre del ejercicio") ;
                int tipoEjercicio = ingresarTipoEjercicio();
                string descripcion = ingresarParametro("la descripción del ejercicio") ;

                if (tipoEjercicio == 1) {
                    controladorCurso->agregarEjercicio(nombreEjercicio, "Traducir", descripcion) ;
                    string fraseATraducir = ingresarParametro("la frase a traducir");
                    string fraseTraducida = ingresarParametro("la frase traducida") ;
                    controladorCurso->agregarFraseTraducir(fraseATraducir, fraseTraducida) ;

                } else if (tipoEjercicio == 2) {
                    controladorCurso->agregarEjercicio(nombreEjercicio, "Completar", descripcion) ;
                    string fraseACompletar = ingresarFraseACompletar() ;
                    nat cantEspacios = contarEspaciosACompletar(fraseACompletar) ;
                    vector<string> conjuntoDePalabras = ingresarConjuntoDePalabras(cantEspacios) ;
                    controladorCurso->agregarFraseCompletar(fraseACompletar, conjuntoDePalabras);
                }

                deseaAgregarEjercicio = ingresarBooleano("¿Desea agregar otro Ejercicio a la Leccion?") ;
                espacioSimple() ;
            }
            
            controladorCurso->agregarLeccion(tema, objetivo) ;
            deseaAgregarLecciones = ingresarBooleano("¿Desea agregar otra lección al curso?") ;
            espacioSimple() ;

        };

        controladorCurso->altaCurso(false) ;
        imprimirMensaje("Se ha dado de alta el curso") ;
    }

    catch (const std::exception &e)
    {
        cancelarOperacion(e.what(), "alta de curso");
        return;
    }
}