#include <iostream>
#include <string>
#include <algorithm>

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

// static vector<string> convertirFraseAPalabras(string frase){
//     vector<string> palabras;

//     //traemos la cantidad de veces que aparece ","
//     int cantidadDeComas;

//     for(char c : frase){
//         if(c == ','){
//             cantidadDeComas++;
//         }
//     };

//     int posicionComa;
//     string palabra;
    
//     //Recorremos según sea la cantidad de comas
//     for(int i=1; i<= cantidadDeComas; i++){
//         //la posicion en la que aparece la coma
//         posicionComa = frase.find(",");

//         palabra = frase.substr(0, posicionComa);

//         //agregamos la palabra al conjunto de palabras
//         palabras.push_back(palabra);

//         frase.erase(0, posicionComa+2); //elimino hasta ", "
//     };

//     if(!frase.empty()){
//         palabras.push_back(frase);
//     };

//     return palabras;
// };

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
        
        // Seleccionar curso
        // ...
         string nombreCurso = seleccionarElemento(nombresCursos, "curso");
        if(nombreCurso != ""){
            imprimirMensaje("Ha seleccionado el curso: " + nombreCurso);
        }else{
            imprimirMensaje("Elija una opcion correcta la proxima");
            return ;
        }

        controladorCurso->seleccionarCurso(nombreCurso);

        cout << endl;

        // Ingresar tema
        string tema = ingresarParametro("el tema");

        espacioSimple();

        // Ingresar objetivo
        string objetivo = ingresarParametro("el objetivo");

        espacioSimple();

        // Crear lección
        Leccion *leccion = new Leccion(tema, objetivo);

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

            string nombre = ingresarParametro("el nombre del ejercicio");

            espacioSimple();

            string descripcion = ingresarParametro("la descripción del ejercicio");

            espacioSimple();

            if (tipoEjercicio == 1) {
                imprimirMensaje("Ha seleccionado la opción 1. Completar Palabras");
                espacioSimple();
                string frase = ingresarFraseACompletar();

                nat cantEspacios = contarEspaciosACompletar(frase);

                vector<string> palabrasFaltantes = ingresarConjuntoDePalabras(cantEspacios);

                leccion->crearEjercicioCompletarYAgregarlo(nombre, descripcion, frase, palabrasFaltantes);

            } else if (tipoEjercicio == 2) {
                imprimirMensaje("Ha seleccionado la opción 2. Traducción");
                string frase = ingresarParametro("la frase a traducir");
                string traduccion = ingresarParametro("la traducción");

                leccion->crearEjercicioTraducirYAgregarlo(nombre, descripcion, frase, traduccion);
            }

            espacioSimple();

            cout << "Desea agregar otro ejercicio? (1. Sí, 0. No): ";
            agregarEjercicios = ingresarOpcion(1);
        }

        espacioSimple();

        // Imprimir datos ingresados
        cout << "Datos ingresados:" << endl;
        cout << "Tema: " << leccion->getTema() << endl;
        cout << "Objetivo: " << leccion->getObjetivo() << endl;
        cout << "Ejercicios:" << endl;
        for (const auto& ejercicio : leccion->getEjercicios()) {
            cout << "- Nombre: " << ejercicio->getNombre() << endl;
            cout << "  Descripción: " << ejercicio->getDescripcion() << endl;
        }

        if(leccion->getEjercicios().empty()){
            imprimirMensaje("No hay ejercicios en la leccion");
        }

        espacioSimple();

        // Dar de alta la lección
        controladorCurso->agregarLeccionACurso(leccion);
        
        // for (const auto& ejercicio : leccion->getEjercicios()) {
        //     controladorCurso->agregarEjercicio(string nombreEjercicio, ejercicio.tipo, ejercicio.descripcion)
        // }

        cout << "Lección agregada con éxito" << endl;
    

}


