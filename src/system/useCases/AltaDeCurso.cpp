#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"

using namespace std;


void Sistema::altaDeCurso() {
    imprimirMensaje("Alta de Curso") ;

    //el caso de uso comienza listando los nickname de los profesores disponibles

    set<string> profesores = controladorUsuario->listarNIcknameProfesores() ;

    if (profesores.size() == 0) {
        cancelarOperacion("No hay profesores registrados en el sistema");
        return ;
    }

    string nicknameProfesor;
    int opcion = -1;

    //se imprime la lista con profesores

    imprimirMensaje("Seleccione un profesor de la lista:") ;
    imprimirSet(profesores, "Profesores") ;

    opcion = ingresarOpcion(profesores.size()) ;
    
    if (opcion == 0) {
        cancelarOperacion("A seleccionado cancelar la operación") ;
        return ;
    }

    nicknameProfesor = obtenerOpcion(profesores, opcion) ;

    try {
        controladorCurso->seleccionarProfesor(nicknameProfesor) ;
        imprimirMensaje("Seleccionó el profesor con nickname: " + nicknameProfesor);
    } catch (invalid_argument& e) {
        cancelarOperacion("No existe un profesor con el nickname " + nicknameProfesor) ;
        return ;
    }

    string nombreCurso = ingresarParametro("el nombre del curso");

    //controlar que no exista el nombre y que no sea vacío
    if(handlerCurso->existeCurso(nombreCurso) || nombreCurso == ""){
        if(nombreCurso == ""){
            cancelarOperacion("Ingrese un nombre para el curso no vacío") ;
        }else{
            cancelarOperacion("Ya existe un curso con el nombre " + nombreCurso) ;
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
        cancelarOperacion("A seleccionado cancelar la operación") ;
        return ;
    }

    Nivel dificultad ;

    if (opcion == 1 || opcion == 2 || opcion == 3) {
        dificultad = static_cast<Nivel>(opcion-1) ;
    } else {
        cancelarOperacion("Opción inválida") ;
        return ;
    }


    controladorCurso->ingresarDatosCurso(nombreCurso, descripcionCurso, dificultad) ;

    set<string> idiomasDeProfesor = controladorUsuario->listarNombresIdiomasDeProfesor(nicknameProfesor) ;

    if (idiomasDeProfesor.size() == 0) {
        cancelarOperacion("El profesor no tiene idiomas registrados en el sistema") ;
        return ;
    }

    imprimirMensaje("Seleccione un idioma de la lista:") ;
    imprimirMensaje("0. Cancelar") ;
    imprimirSet(idiomasDeProfesor, "Idiomas") ;

    opcion = ingresarOpcion(idiomasDeProfesor.size()) ;

    if (opcion == 0) {
        cancelarOperacion("A seleccionado cancelar la operación") ;
        return ;
    }

    string nombreIdioma = obtenerOpcion(idiomasDeProfesor, opcion) ;

    try {
        controladorCurso->seleccionarIdioma(nombreIdioma) ;
        imprimirMensaje("Seleccionó el idioma: " + nombreIdioma);
    } catch (invalid_argument& e) {
        cancelarOperacion("No existe un idioma con el nombre " + nombreIdioma) ;
        return ;
    }

    //TODO: No esta contemplado las previas de un curso

    imprimirMensaje("¿Desea agregar lecciones al curso?") ;
    imprimirMensaje("0. Cancelar") ;
    imprimirMensaje("1. Si") ;
    imprimirMensaje("2. No") ;
    
    opcion = ingresarOpcion(2) ;

    if (opcion == 0) {
        cancelarOperacion("A seleccionado cancelar la operación") ;
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
                cancelarOperacion("A seleccionado cancelar la operación") ;
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
        cancelarOperacion("No se pudo dar de alta el curso") ;
        return ;
    }




}
