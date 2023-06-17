#include <iostream>
#include <string>

#include "../../../include/system/Sistema.h"

#include "../../../include/system/operaciones.h"

using namespace std;

void Sistema::consultarEstadisticas() {
    imprimirMensaje("Consultar Estadisticas");
    std::cout << "¿Qué tipo de estadísticas desea consultar?" << std::endl;
        std::cout << "1. Estadísticas de estudiantes" << std::endl;
        std::cout << "2. Estadísticas de profesores" << std::endl;
        std::cout << "3. Estadísticas de cursos" << std::endl;

        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarEstadisticasEstudiantes();
                break;
            case 2:
                mostrarEstadisticasProfesores();
                break;
            case 3:
                mostrarEstadisticasCursos();
                break;
            default:
                std::cout << "Opción inválida." << std::endl;
                break;
        }
}

 void mostrarEstadisticasEstudiantes() {
        // Obtener lista de estudiantes (ejemplo)
        std::vector<Estudiante> estudiantes;
        estudiantes.push_back(Estudiante("Estudiante 1"));
        estudiantes.push_back(Estudiante("Estudiante 2"));
        estudiantes.push_back(Estudiante("Estudiante 3"));

        // Mostrar lista de estudiantes
        std::cout << "Lista de estudiantes:" << std::endl;
        for (size_t i = 0; i < estudiantes.size(); i++) {
            std::cout << i + 1 << ". " << estudiantes[i].obtenerNombre() << std::endl;
        }

        int seleccion;
        std::cout << "Seleccione un estudiante: ";
        std::cin >> seleccion;

        if (seleccion >= 1 && seleccion <= estudiantes.size()) {
            Estudiante estudianteSeleccionado = estudiantes[seleccion - 1];
            // Obtener cursos del estudiante seleccionado (ejemplo)
            std::vector<Curso> cursos;
            cursos.push_back(Curso("Curso 1", 7, 10));
            cursos.push_back(Curso("Curso 2", 4, 8));

            std::cout << "Cursos inscriptos por el estudiante " << estudianteSeleccionado.obtenerNombre() << ":" << std::endl;
            for (const Curso& curso : cursos) {
                std::cout << "Nombre: " << curso.obtenerNombre() << std::endl;
                std::cout << "Porcentaje de avance: " << curso.obtenerPorcentajeAvance() << "%" << std::endl;
            }
        } else {
            std::cout << "Selección inválida." << std::endl;
        }
    }

    void mostrarEstadisticasProfesores() {
        // Obtener lista de profesores (ejemplo)
        std::vector<Profesor> profesores;
        profesores.push_back(Profesor("Profesor 1"));
        profesores.push_back(Profesor("Profesor 2"));
        profesores.push_back(Profesor("Profesor 3"));

        // Mostrar lista de profesores
        std::cout << "Lista de profesores:" << std::endl;
        for (size_t i = 0; i < profesores.size(); i++) {
            std::cout << i + 1 << ". " << profesores[i].obtenerNombre() << std::endl;
        }

        int seleccion;
        std::cout << "Seleccione un profesor: ";
        std::cin >> seleccion;

        if (seleccion >= 1 && seleccion <= profesores.size()) {
            Profesor profesorSeleccionado = profesores[seleccion - 1];
            // Obtener cursos propuestos por el profesor seleccionado (ejemplo)
            std::vector<Curso> cursos;
            cursos.push_back(Curso("Curso 1", 6, 10));
            cursos.push_back(Curso("Curso 2", 8, 12));

            std::cout << "Cursos propuestos por el profesor " << profesorSeleccionado.obtenerNombre() << ":" << std::endl;
            for (const Curso& curso : cursos) {
                std::cout << "Nombre: " << curso.obtenerNombre() << std::endl;
                std::cout << "Porcentaje promedio de avance: " << curso.obtenerPorcentajeAvance() << "%" << std::endl;
            }
        } else {
            std::cout << "Selección inválida." << std::endl;
        }
    }

    void mostrarEstadisticasCursos() {
        // Obtener lista de cursos (ejemplo)
        std::vector<Curso> cursos;
        cursos.push_back(Curso("Curso 1", 7, 10));
        cursos.push_back(Curso("Curso 2", 4, 8));
        cursos.push_back(Curso("Curso 3", 9, 15));

        // Mostrar lista de cursos
        std::cout << "Lista de cursos:" << std::endl;
        for (size_t i = 0; i < cursos.size(); i++) {
            std::cout << i + 1 << ". " << cursos[i].obtenerNombre() << std::endl;
        }

        int seleccion;
        std::cout << "Seleccione un curso: ";
        std::cin >> seleccion;

        if (seleccion >= 1 && seleccion <= cursos.size()) {
            Curso cursoSeleccionado = cursos[seleccion - 1];

            std::cout << "Información del curso " << cursoSeleccionado.obtenerNombre() << ":" << std::endl;
            std::cout << "Porcentaje promedio de avance: " << cursoSeleccionado.obtenerPorcentajeAvance() << "%" << std::endl;
        } else {
            std::cout << "Selección inválida." << std::endl;
        }
    }
};