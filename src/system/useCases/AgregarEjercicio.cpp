#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"

#include "../../../include/classes/Curso/Completar.h"
#include "../../../include/classes/Curso/Traducir.h"

using namespace std;

/*Caso de uso Agregar Ejercicio*/
/* El caso de uso comienza cuando se desea agregar un nuevo ejercicio a una lección de
un curso. Para ello, el Sistema lista todos los cursos no habilitados y el Usuario
selecciona uno. Luego, el Sistema lista de forma ordenada las lecciones definidas y el
Usuario selecciona una. El Usuario ingresa el tipo de ejercicio y la descripción. Para los
ejercicios de completar palabras, el Usuario ingresa la frase a completar, donde las
palabras faltantes se representan mediante 3 guiones, por ejemplo, “Mi --- es Juan y
tengo 21 ---”, y, por otro lado, el conjunto ordenado de palabras separados por una
coma que conforman la solución (en el caso anterior sería: “nombre”, “años”). Por otra
parte, para los ejercicios de traducción, el Usuario ingresa la frase a traducir, seguida de
la frase traducida, por ejemplo, “Soy Juan”, y su traducción, “I am Juan”. Una vez que
el Usuario termina, el Sistema da de alta el ejercicio para la lección seleccionada,
dentro del curso seleccionado. */

void Sistema::agregarEjercicio() {
    imprimirMensaje("Agregar Ejercicio");

    //Listar cursos no habilitados

    set<string> nombreCursos = controladorCurso->listarCursosNoHabilitados();
    if(nombreCursos.empty()){
        imprimirMensaje("No hay cursos disponibles");
        return;
    }

    // imprimirSet(nombreCursos, "Cursos disponibles");

    //Seleccionar curso
    string nombreCurso = seleccionarElemento(nombreCursos, "curso");
    if(nombreCurso != ""){
        imprimirMensaje("Ha seleccionado el curso: " + nombreCurso);
    }else{
        imprimirMensaje("Elija una opción correcta la próxima");
    }

    //guardamos el nombre del curso en el controlador
    controladorCurso->seleccionarCurso(nombreCurso);

    cout << endl;

    //Listar lecciones en orden
    Curso *curso = handlerCurso->obtenerCurso(nombreCurso);
    vector<string> lecciones = controladorCurso->listarLecciones(curso);
    vector<Leccion*> leccionesCurso = curso->getLecciones();
    cout << "A continuación, se listan las lecciones del curso " << nombreCurso << endl;
    // imprimirVector(lecciones, "lecciones");
    espacioSimple();
    //seleccionar leccion
    int indiceLeccion = seleccionarElemento(lecciones, "leccion");
    
    if(indiceLeccion == -1){
        imprimirMensaje("Cancelando operación");
        imprimirMensaje("EL número indicado no es correcto");
        return ;
    }

    //guardamos la leccion elegida en la variable leccion
    Leccion *leccion = leccionesCurso[indiceLeccion];
    controladorCurso->setLeccionActual(leccion);
    espacioSimple();

    set<string> tipo;
    tipo.insert("Completar palabras");
    tipo.insert("Traducir");

    imprimirMensaje("Ingrese los datos del ejercicio:");
    // imprimirSet(tipo, "tipo de ejercicio");
    espacioSimple();

    string tipoEjercicio = seleccionarElemento(tipo, "tipo de ejercicio");
    espacioSimple();
    string descripcion = ingresarParametro("la descripcion");
    espacioSimple();
    if(tipoEjercicio == "Completar palabras"){
        imprimirMensaje("Ha seleccionado la opción 1 - Completar Palabras");
        espacioSimple();
        string frase = ingresarFraseACompletar();

        nat cantEspacios = contarEspaciosACompletar(frase);

        vector<string> palabrasFaltantes = ingresarConjuntoDePalabras(cantEspacios);
        controladorCurso->darDeAltaCompletar(descripcion, frase, palabrasFaltantes);
        
    }else{
        imprimirMensaje("Ha seleccionado la opción 2. Traducción");
        string frase = ingresarParametro("la frase a traducir");
        string traduccion = ingresarParametro("la traducción");
        controladorCurso->darDeAltaTraducir(descripcion, frase, traduccion);
    }

    imprimirMensaje("Se dio de alta el ejercicio con éxito");

    set<Ejercicio*> ejers = leccion->getEjercicios();
    //IMPRIMIMOS DATOS INGRESADOS
    string desc;
    int i = 1;
    imprimirMensaje("Se imprimen los ejercicios de la lección elegida:");
    for (Ejercicio* ej : ejers) {
        cout << "-----Ejercicio " << i << "-----" << endl;
        if (Completar* ejCompletar = dynamic_cast<Completar*>(ej)) {
            desc = ejCompletar->getDescripcion();
            cout << "Descripción: " << desc << endl;
            string frase = ejCompletar->getFraseACompletar();
            cout << "Frase a completar: " << frase << endl;
            vector<string> palabras = ejCompletar->getPalabrasFaltantes();
            imprimirMensaje("Las palabras faltantes son:");
            imprimirVector(palabras, "palabras faltantes");
        } else if (Traducir* ejTraducir = dynamic_cast<Traducir*>(ej)) {
            desc = ejTraducir->getDescripcion();
            cout << "Descripción: " << desc << endl;
            string frase = ejTraducir->getFraseATraducir();
            cout << "Frase a traducir: " << frase << endl;
            string correcta = ejTraducir->getFraseCorrecta();
            cout << "Frase traducida: " << correcta << endl;
        }
        i++;
    }

}