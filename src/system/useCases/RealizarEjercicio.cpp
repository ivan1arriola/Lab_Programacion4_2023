#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"

using namespace std;

void Sistema::realizarEjercicio() {
    imprimirMensaje("Realizar Ejercicio");

    // // Obtener nickname del estudiante
    //     std::string nickname;
    //     std::cout << "Ingrese el nickname del estudiante: ";
    //     std::cin >> nickname;

    //     // Obtener lista de cursos en los que está inscripto el estudiante y aún no ha aprobado
    //     std::vector<Curso> cursos = obtenerCursosPendientes(nickname);

    //     // Mostrar lista de cursos
    //     std::cout << "Cursos pendientes del estudiante " << nickname << ":" << std::endl;
    //     for (size_t i = 0; i < cursos.size(); i++) {
    //         std::cout << i + 1 << ". " << cursos[i].obtenerNombre() << std::endl;
    //     }

    //     int seleccionCurso;
    //     std::cout << "Seleccione un curso: ";
    //     std::cin >> seleccionCurso;

    //     if (seleccionCurso >= 1 && seleccionCurso <= cursos.size()) {
    //         Curso cursoSeleccionado = cursos[seleccionCurso - 1];

    //         // Obtener lista de ejercicios no aprobados de la última lección del curso
    //         std::vector<Ejercicio> ejercicios = obtenerEjerciciosPendientes(cursoSeleccionado);

    //         if (!ejercicios.empty()) {
    //             std::cout << "Ejercicios pendientes de la última lección del curso " << cursoSeleccionado.obtenerNombre() << ":" << std::endl;
    //             for (size_t i = 0; i < ejercicios.size(); i++) {
    //                 std::cout << i + 1 << ". " << ejercicios[i].obtenerProblema() << std::endl;
    //             }

    //             int seleccionEjercicio;
    //             std::cout << "Seleccione un ejercicio: ";
    //             std::cin >> seleccionEjercicio;

    //             if (seleccionEjercicio >= 1 && seleccionEjercicio <= ejercicios.size()) {
    //                 Ejercicio ejercicioSeleccionado = ejercicios[seleccionEjercicio - 1];

    //                 std::cout << "Problema del ejercicio:" << std::endl;
    //                 std::cout << ejercicioSeleccionado.obtenerProblema() << std::endl;

    //                 // Ingresar solución del estudiante
    //                 std::string solucionEstudiante;
    //                 std::cout << "Ingrese la solución del ejercicio: ";
    //                 std::cin >> solucionEstudiante;

    //                 // Verificar solución
    //                 if (solucionEstudiante == ejercicioSeleccionado.obtenerSolucion()) {
    //                     std::cout << "¡Solución correcta! Ejercicio aprobado." << std::endl;
    //                     ejercicioSeleccionado.marcarAprobado();
    //                 } else {
    //                     std::cout << "Solución incorrecta. Ejercicio no aprobado." << std::endl;
    //                 }
    //             } else {
    //                 std::cout << "Selección inválida." << std::endl;
    //             }
    //         } else {
    //             std::cout << "No hay ejercicios pendientes en la última lección del curso." << std::endl;
    //         }
    //     } else {
    //         std::cout << "Selección inválida." << std::endl;
    //     }

}
