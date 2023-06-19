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

        string cursoNoAprob = seleccionarElemento(c, "Cursos inscritos pero no aprobados");

        if (cursoNoAprob == "")
            throw invalid_argument("No ha seleccionado ningun curso");

        controladorCurso->seleccionarCurso(cursoNoAprob);

        set<string> ej = controladorCurso->mostrarEjerciciosNoAprobados();

        string ejercNoAprob = seleccionarElemento(ej, "Ejercicios no aprobados");
        if (ejercNoAprob == "")
            throw invalid_argument("No ha seleccionado ningun ejercicio");

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
