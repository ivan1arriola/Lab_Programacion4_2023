#include <iostream>
#include <string>
#include <algorithm>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"
#include "../../../include/classes/Curso/Traducir.h"
#include "../../../include/classes/Curso/Completar.h"

using namespace std;

void Sistema::realizarEjercicio()
{
    try
    {
        imprimirMensaje("Realizar Ejercicio");

        set<string> lista = controladorUsuario->listarNIcknameEstudiantes();

        string nom = seleccionarElemento(lista, "Usuarios");

        controladorCurso->ingresarNicknameEstudiante(nom);

        set<string> c = controladorCurso->listarCursosInscrip();

        if (c.size() == 0)
            throw invalid_argument(nom + " no se ha inscripto en ningun curso");

        imprimirOpcionesSet(c, "Cursos inscritos pero no aprobados");

        int opcion = ingresarOpcion(c.size());
        if (opcion != 0)
        {
            string nomcurso = obtenerOpcion(c, opcion);
            controladorCurso->seleccionarCurso(nomcurso);
            set<string> ej = controladorCurso->mostrarEjerciciosNoAprobados();
            imprimirOpcionesSet(ej, "Ejercicios no aprobados");
            int opcion2 = ingresarOpcion(ej.size());

            if (opcion2 != 0)
            {
                string nomEj = obtenerOpcion(ej, opcion2);
                controladorCurso->seleccionarEjercicio(nomEj);
                controladorCurso->corregirEj();
            }
        }
    }

    catch (const std::exception &e)
    {
        cancelarOperacion(e.what(), "Realizar Ejercicio");
    }
    {
    }
}
