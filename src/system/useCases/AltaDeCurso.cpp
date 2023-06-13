#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"

using namespace std;

static void cancelarOperacion(string error = "")
{
    if (error != "")
    {
        imprimirMensaje(error);
    }
    imprimirMensaje("No se puede dar de alta el curso");
    imprimirMensaje("Cancelando operación");
}

static void imprimirCursos(set<Curso*> cursos){
    string nombre;
    for(auto it = cursos.begin(); it != cursos.end(); ++it){
        nombre = (*it)->getNombre();
        imprimirMensaje(nombre);
    }
}

void Sistema::altaDeCurso()
{

    // lista con nombre de todos los cursos (habilitados o no habilitados)
    set<string> cursos = controladorCurso->listarNombreCursos();

    imprimirMensaje("Alta de Curso");

    // el caso de uso comienza listando los nickname de los profesores disponibles

    set<string> profesores = controladorUsuario->listarNIcknameProfesores();

    if (profesores.size() == 0)
    {
        cancelarOperacion("No hay profesores registrados en el sistema");
        return;
    }

    string nicknameProfesor;
    int opcion = -1;

    // se imprime la lista con profesores

    imprimirMensaje("Seleccione un profesor de la lista:");
    imprimirMensaje("0- Cancelar");
    imprimirSet(profesores, "Profesores");

    opcion = ingresarOpcion(profesores.size());

    if (opcion == 0)
    {
        cancelarOperacion("A seleccionado cancelar la operación");
        return;
    }

    nicknameProfesor = obtenerOpcion(profesores, opcion);

    try
    {
        controladorCurso->seleccionarProfesor(nicknameProfesor);
        imprimirMensaje("Seleccionó el profesor con nickname: " + nicknameProfesor);
    }
    catch (invalid_argument &e)
    {
        cancelarOperacion("No existe un profesor con el nickname " + nicknameProfesor);
        return;
    }

    string nombreCurso = ingresarParametro("el nombre del curso");

    // controlar que no exista el nombre y que no sea vacío
    if (handlerCurso->existeCurso(nombreCurso) || nombreCurso == "")
    {
        if (nombreCurso == "")
        {
            cancelarOperacion("Ingrese un nombre para el curso no vacío");
        }
        else
        {
            cancelarOperacion("Ya existe un curso con el nombre " + nombreCurso);
        }
        return;
    }

    string descripcionCurso = ingresarParametro("la descripción del curso");

    imprimirMensaje("Ingrese la dificultad del curso:");
    imprimirMensaje("0. Cancelar");
    imprimirMensaje("1. Principiante");
    imprimirMensaje("2. Medio");
    imprimirMensaje("3. Avanzado");

    opcion = ingresarOpcion(3);

    if (opcion == 0)
    {
        cancelarOperacion("A seleccionado cancelar la operación");
        return;
    }

    Nivel dificultad;

    if (opcion == 1 || opcion == 2 || opcion == 3)
    {
        dificultad = static_cast<Nivel>(opcion - 1);
    }
    else
    {
        cancelarOperacion("Opción inválida");
        return;
    }

    controladorCurso->ingresarDatosCurso(nombreCurso, descripcionCurso, dificultad);

    set<string> idiomasDeProfesor = controladorUsuario->listarNombresIdiomasDeProfesor(nicknameProfesor);

    if (idiomasDeProfesor.size() == 0)
    {
        cancelarOperacion("El profesor no tiene idiomas registrados en el sistema");
        return;
    }

    imprimirMensaje("Seleccione un idioma de la lista:");
    imprimirMensaje("0. Cancelar");
    imprimirSet(idiomasDeProfesor, "Idiomas");

    opcion = ingresarOpcion(idiomasDeProfesor.size());

    if (opcion == 0)
    {
        cancelarOperacion("A seleccionado cancelar la operación");
        return;
    }

    string nombreIdioma = obtenerOpcion(idiomasDeProfesor, opcion);

    try
    {
        controladorCurso->seleccionarIdioma(nombreIdioma);
        imprimirMensaje("Seleccionó el idioma: " + nombreIdioma);
    }
    catch (invalid_argument &e)
    {
        cancelarOperacion("No existe un idioma con el nombre " + nombreIdioma);
        return;
    }

    // Siguiente paso del caso de uso, agregar cursos previos

    // si no hay cursos disponibles, no se agregan

    bool deseaAgregarCursos;
    // Consultamos si desea agregar cursos previos
    cout << endl;
    imprimirMensaje("¿Desea agregar cursos previos?");
    imprimirMensaje("0- Cancelar todo");
    imprimirMensaje("1- Sí");
    imprimirMensaje("2- No");
    cout << endl;
    opcion = ingresarOpcion(2);

    if (opcion == 0)
    {
        cancelarOperacion();
        return;
    };

    int posicion;

    deseaAgregarCursos = opcion == 1;
    // conjunto que almacenará los cursos previos
    // se insertarán estos cursos al dar de alta el curso
    set<Curso *> cursosPrevios;
    // variable para guardar el curso previo elegido
    Curso *cursoPrev;
    // se listan los cursos habilitados en el sistema
    set<string> cursosDisponibles = controladorCurso->listarCursosHabilitados();
    string cp; // variable para guardar el nombre del curso previo actual

    while (deseaAgregarCursos && cursosDisponibles.size() > 0)
    {   
        cout << endl;
        imprimirMensaje("0- Cancelar");
        imprimirSet(cursosDisponibles, "cursos habilitados");
        opcion = ingresarOpcion(cursosDisponibles.size());

        if (opcion == 0)
        {
            // si desea cancelar, termina el bucle
            deseaAgregarCursos = false;
        }
        else
        {
            opcion = opcion - 1;
            posicion = 0;
            auto it = cursosDisponibles.begin();
            // recorro la lista de cursos hasta encontrar el que eligio el usuario
            // corto la recorrida cuando encuentro la posicion o cuando salimos del conjunto
            while (it != cursosDisponibles.end() && opcion != posicion)
            {
                posicion++;
                it++;
            };
            // eliminamos el curso elegido de la lista de cursos habilitados
            // cuando le mostremos al usuario los cursos habilitados no queremos repetir la eleccion
            if (it != cursosDisponibles.end())
            {
                cp = *it;
                cursosDisponibles.erase(it);
                cursoPrev = handlerCurso->obtenerCurso(cp);
                // insertamos el curso en el conjunto de cursos previos
                cursosPrevios.insert(cursoPrev);
            }else{
                cout << endl;
                imprimirMensaje("No ingresaste un curso disponible");
            }
            cout << endl;
            imprimirMensaje("¿Desea continuar agregando cursos?");
            imprimirMensaje("0- Cancelar todo");
            imprimirMensaje("1- Sí");
            imprimirMensaje("2- No");
            opcion = ingresarOpcion(2);

            if (opcion == 0){
                cancelarOperacion();
                return;
            };

            deseaAgregarCursos = opcion == 1;
        }
    };

    //Si abandonamos el bucle por la segunda condición ya no hay cursos para elegir
    if (cursosDisponibles.size() == 0){
        imprimirMensaje("No hay cursos disponibles para agregar");
        cout << endl;
    };

    //Si seleccionaron cursos previos
    //se imprimen en pantalla
    if(cursosPrevios.size() != 0 ){
        cout << endl;
        imprimirMensaje("A continuación le mostramos los cursos previos elegidos:");
        cout << endl;
        imprimirCursos(cursosPrevios);
    };

    cout << endl;
    imprimirMensaje("¿Desea agregar lecciones al curso?");
    imprimirMensaje("0. Cancelar");
    imprimirMensaje("1. Si");
    imprimirMensaje("2. No");

    opcion = ingresarOpcion(2);

    if (opcion == 0)
    {
        cancelarOperacion("A seleccionado cancelar la operación");
        return;
    }

    if (opcion == 1)
    {
        bool quiereAgregarLecciones = true;
        do
        {

            string tema = ingresarParametro("el tema de la lección");

            string objetivo = ingresarParametro("el objetivo de la lección");

            controladorCurso->agregarLeccion(tema, objetivo);

            imprimirMensaje("¿Desea agregar otra lección al curso?");
            imprimirMensaje("0. Cancelar");
            imprimirMensaje("1. Si");
            imprimirMensaje("2. No");

            opcion = ingresarOpcion(2);

            if (opcion == 0)
            {
                cancelarOperacion("A seleccionado cancelar la operación");
                return;
            }

            if (opcion == 2)
            {
                quiereAgregarLecciones = false;
            }

        } while (quiereAgregarLecciones);
    }

    // TODO: No esta contemplado los ejercicios de una leccion

    // Dar de alta el curso
    try
    {
        controladorCurso->altaCurso(false);
        imprimirMensaje("Se ha dado de alta el curso");
    }
    catch (invalid_argument &e)
    {
        cancelarOperacion("No se pudo dar de alta el curso");
        return;
    }
}
