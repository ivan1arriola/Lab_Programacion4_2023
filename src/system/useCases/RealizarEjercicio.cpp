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

        set<string> lista = controladorUsuario->listarNicknameUsuarios();

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
                Ejercicio *e = controladorCurso->getejActual();

                if (Traducir *tr = dynamic_cast<Traducir *>(e))
                {
                    string sol;
                    cout << "Ejercicio de traduccion " << endl
                         << "frase a traducrir: " << tr->getFraseATraducir() << endl;
                    cout << "Ingrese la solucion:" << endl;
                    cin >> sol;
                    controladorCurso->ingresarSolucionTraducir(sol);
                    if (controladorCurso->getSolT_actual() == tr->getFraseCorrecta())
                    {
                        controladorCurso->marcarEjercicioAprobado();
                        cout << "Respuesta correcta" << endl;
                    }
                    else
                    {
                        cout << "Respuesta incorrecta" << endl;
                        controladorCurso->marcarEjercicioNoAprobado();
                    }
                }

                else if (Completar *c = dynamic_cast<Completar *>(e))
                {
                    set<string> solucion;
                    cout << "Ejercicio de completar " << endl
                         << "frase a completar: " << c->getFraseACompletar() << endl;
                    cout << "Ingrese las palabras faltantes:" << endl;
                    for (long unsigned int i = 0; i < c->getPalabrasFaltantes().size(); i++)
                    {
                        string palabra;
                        cin >> palabra;
                        solucion.insert(palabra);
                    }
                    controladorCurso->ingresarSolucionCompletar(solucion);
                    bool soniguales = true;
                    vector<string> v = c->getPalabrasFaltantes();
                    set<string> s = controladorCurso->getSolC_actual();

                    if (v.size() == s.size())
                    {

                        vector<string> sortedVector = v;
                        sort(sortedVector.begin(), sortedVector.end());
                        set<string> sortedSet = s;
                        vector<string> sortedSetVector(sortedSet.begin(), sortedSet.end());
                        soniguales = (sortedVector == sortedSetVector);

                        if (soniguales)
                        {
                            controladorCurso->marcarEjercicioAprobado();
                            cout << "Respuesta correcta" << endl;
                        }
                        else
                        {
                            cout << "Respuesta incorrecta" << endl;
                            controladorCurso->marcarEjercicioNoAprobado();
                        }
                    }

                    else
                    {
                        controladorCurso->marcarEjercicioNoAprobado();
                    }
                }
            }
        }
    }
    catch (const std::exception &e)
    {
        cancelarOperacion(e.what(), "Realizar Ejercicio");
    }
}
