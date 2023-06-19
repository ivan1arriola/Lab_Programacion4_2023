#include <iostream>
#include <string>
#include <set>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"

using namespace std;

/*
El caso de uso comienza cuando un usuario desea consultar estadísticas del sistema.
Para ello, primero el Sistema pregunta si desea obtener estadísticas de estudiantes,
profesores o cursos. Si el Usuario selecciona estadísticas de estudiantes, el Sistema lista
todos los estudiantes y el Usuario selecciona uno. A continuación, el Sistema lista todos
los cursos a los que se ha inscripto el estudiante, así como el porcentaje de avance en
cada uno, medido como la cantidad de ejercicios aprobados sobre la cantidad total de
ejercicios del curso. Por otra parte, si el Usuario selecciona estadísticas de profesores,
el Sistema lista todos los profesores y el Usuario selecciona uno. A continuación, el
Sistema lista todos los cursos propuestos por el profesor seleccionado, así como un
promedio para cada curso (sobre todos los estudiantes inscriptos al curso), del grado de
avance (tal como se definió anteriormente). Finalmente, si el Usuario selecciona
estadísticas de cursos, el Sistema lista todos los cursos y el Usuario selecciona uno. A
continuación, el Sistema lista información del curso, incluyendo un promedio del grado
de avance calculado sobre sobre todos los estudiantes, tal como se definió
anteriormente.
*/

void Sistema::consultarEstadisticas() {
    imprimirMensaje("Consultar Estadisticas");
    cout << "¿Qué tipo de estadísticas desea consultar?" << endl;
    cout << "0. Cancelar" << endl;
    cout << "1. Estadísticas de estudiantes" << endl;
    cout << "2. Estadísticas de profesores" << endl;
    cout << "3. Estadísticas de cursos" << endl;

        int opcion = ingresarOpcion(3);

        if(opcion == 0){
            imprimirMensaje("Ha seleccionado cancelar todo");
            cancelarOperacion("", "consultar estadísticas");
            return ;
        }

        if(opcion == 1){
            //listamos los nickname de estudiantes
            set<string> estudiantes;
            estudiantes = controladorEstadistica->listarNicknameEstudiantes();
            imprimirSet(estudiantes, "estudiantes");
            int e = ingresarOpcion(estudiantes.size());
            if(e == 0){
                imprimirMensaje("Ha seleccionado cancelar todo");
                cancelarOperacion("", "consultar estadísticas");
                return ;
            }
            string estudiante = obtenerOpcion(estudiantes, e);
            controladorEstadistica->seleccionarEstudiante(estudiante);
            cout << "Usted ha seleccionado el estudiante " << e << " - " << estudiante << endl;
            set<DTDataCursoEstudiante*> dataCursoEstudiante = controladorEstadistica->listarCursosEstudiante();
            if(dataCursoEstudiante.empty()){
                imprimirMensaje("No hay datos para mostrar de los cursos del estudiante");
            }else{
                int indice = 1;
                for(DTDataCursoEstudiante* dt : dataCursoEstudiante){
                    cout << "Datos del curso " << indice << ":" << endl;
                    cout << *dt << endl; 
                    ++indice;
                }
            }                
        }else if(opcion == 2){
            set<string> profesores = controladorEstadistica->listarNIcknameProfesores();
            imprimirSet(profesores, "profesores");
            int p = ingresarOpcion(profesores.size());
            if(p == 0){
                imprimirMensaje("Ha seleccionado cancelar todo");
                cancelarOperacion("", "consultar estadísticas");
                return ;
            }
            string profesor = obtenerOpcion(profesores, p);
            controladorEstadistica->seleccionarProfesor(profesor);
            cout << "Usted ha seleccionado el profesor " << p << " - " << profesor << endl;
            set<DTDataCursoProfesor*> dataCursoProfesor = controladorEstadistica->listarCursosProfesor();
            if(dataCursoProfesor.empty()){
                imprimirMensaje("No hay datos para mostrar de los cursos del profesor");
            }else{
                int indice = 1;
                for(DTDataCursoProfesor* dt : dataCursoProfesor){
                    cout << "Datos del curso " << indice << ":" << endl;
                    cout << *dt << endl; 
                    ++indice;
                }
            }
        }else{
            set<string> cursos = controladorEstadistica->obtenerCursos();
            imprimirSet(cursos, "cursos");
            int c = ingresarOpcion(cursos.size());
            if(c == 0){
                imprimirMensaje("Ha seleccionado cancelar todo");
                cancelarOperacion("", "consultar estadísticas");
                return ;
            }
            string curso = obtenerOpcion(cursos, c);
            controladorEstadistica->seleccionarCurso(curso);
            cout << "Usted ha seleccionado el curso: " << c << " - " << curso << endl;
            DTDataInfoCurso* dataInfoCursos = controladorEstadistica->listarInfoCurso();
            imprimirMensaje("Datos del curso:");
            cout << *dataInfoCursos << endl;
        }
}  
