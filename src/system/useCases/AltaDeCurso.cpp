#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"

using namespace std;

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


void Sistema::altaDeCurso() {
    imprimirMensaje("Alta de Curso") ;

    //el caso de uso comienza listando los nickname de los profesores disponibles

    set<string> profesores = controladorUsuario->listarNIcknameProfesores() ;

    if (profesores.size() == 0) {
        cancelarOperacion("No hay profesores registrados en el sistema", "Alta de Curso");
        return ;
    }

    string nicknameProfesor;
    int opcion = -1;

    //se imprime la lista con profesores

    imprimirMensaje("Seleccione un profesor de la lista:") ;
    imprimirSet(profesores, "Profesores") ;

    opcion = ingresarOpcion(profesores.size()) ;
    
    if (opcion == 0) {
        cancelarOperacion("A seleccionado cancelar la operación", "Alta de Curso") ;
        return ;
    }

    nicknameProfesor = obtenerOpcion(profesores, opcion) ;

    try {
        controladorCurso->seleccionarProfesor(nicknameProfesor) ;
        imprimirMensaje("Seleccionó el profesor con nickname: " + nicknameProfesor);
    } catch (invalid_argument& e) {
        cancelarOperacion("No existe un profesor con el nickname " + nicknameProfesor, "Alta de Curso") ;
        return ;
    }

    string nombreCurso = ingresarParametro("el nombre del curso");

    //controlar que no exista el nombre y que no sea vacío
    if(handlerCurso->existeCurso(nombreCurso) || nombreCurso == ""){
        if(nombreCurso == ""){
            cancelarOperacion("Ingrese un nombre para el curso no vacío", "Alta de Curso") ;
        }else{
            cancelarOperacion("Ya existe un curso con el nombre " + nombreCurso, "Alta de Curso") ;
        }
        return ;
    }

    string descripcionCurso = ingresarParametro("la descripción del curso");

    imprimirMensaje("Ingrese la dificultad del curso:") ;
    imprimirMensaje("1. Principiante") ;
    imprimirMensaje("2. Medio") ;
    imprimirMensaje("3. Avanzado") ;

    opcion = ingresarOpcion(3) ;

    if (opcion == 0) {
        cancelarOperacion("A seleccionado cancelar la operación", "Alta de Curso") ;
        return ;
    }

    Nivel dificultad ;

    if (opcion == 1 || opcion == 2 || opcion == 3) {
        dificultad = static_cast<Nivel>(opcion-1) ;
    } else {
        cancelarOperacion("Opción inválida", "Alta de Curso") ;
        return ;
    }


    controladorCurso->ingresarDatosCurso(nombreCurso, descripcionCurso, dificultad) ;

    set<string> idiomasDeProfesor = controladorUsuario->listarNombresIdiomasDeProfesor(nicknameProfesor) ;

    if (idiomasDeProfesor.size() == 0) {
        cancelarOperacion("El profesor no tiene idiomas registrados en el sistema", "Alta de Curso") ;
        return ;
    }

    imprimirMensaje("Seleccione un idioma de la lista:") ;
    imprimirMensaje("0. Cancelar") ;
    imprimirSet(idiomasDeProfesor, "Idiomas") ;

    opcion = ingresarOpcion(idiomasDeProfesor.size()) ;

    if (opcion == 0) {
        cancelarOperacion("A seleccionado cancelar la operación", "Alta de Curso") ;
        return ;
    }

    string nombreIdioma = obtenerOpcion(idiomasDeProfesor, opcion) ;

    try {
        controladorCurso->seleccionarIdioma(nombreIdioma) ;
        imprimirMensaje("Seleccionó el idioma: " + nombreIdioma);
    } catch (invalid_argument& e) {
        cancelarOperacion("No existe un idioma con el nombre " + nombreIdioma, "Alta de Curso") ;
        return ;
    }

    //TODO: No esta contemplado las previas de un curso

    imprimirMensaje("¿Desea agregar lecciones al curso?") ;
    imprimirMensaje("0. Cancelar") ;
    imprimirMensaje("1. Si") ;
    imprimirMensaje("2. No") ;
    
    opcion = ingresarOpcion(2) ;

    if (opcion == 0) {
        cancelarOperacion("A seleccionado cancelar la operación", "Alta de Curso") ;
        return ;
    }

    if (opcion == 1) {
        bool quiereAgregarLecciones = true ;
        do {

            string tema = ingresarParametro("el tema de la lección") ;

            string objetivo = ingresarParametro("el objetivo de la lección") ;

            controladorCurso->agregarLeccion(tema, objetivo) ;

            imprimirMensaje("¿Desea agregar otra lección al curso?") ;
            imprimirMensaje("0. Cancelar") ;
            imprimirMensaje("1. Si") ;
            imprimirMensaje("2. No") ;
            
            opcion = ingresarOpcion(2) ;

            if (opcion == 0) {
                cancelarOperacion("A seleccionado cancelar la operación", "Alta de Curso") ;
                return ;
            }

            if (opcion == 2) {
                quiereAgregarLecciones = false ;
            }

        } while (quiereAgregarLecciones) ;
    }






    //TODO: No esta contemplado los ejercicios de una leccion


    // Dar de alta el curso
    try {
        controladorCurso->altaCurso(false) ;
        imprimirMensaje("Se ha dado de alta el curso") ;
    } catch (invalid_argument& e) {
        cancelarOperacion("No se pudo dar de alta el curso", "Alta de Curso") ;
        return ;
    }




}
