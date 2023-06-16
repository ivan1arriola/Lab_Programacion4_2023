#ifndef ICONTROLADORCURSO
#define ICONTROLADORCURSO

#include <string>
#include <set>
#include <vector>

#include "../datatypes/DTDataCurso.h"
#include "../datatypes/DTDataLeccion.h"
#include "../datatypes/DTEjercicio.h"
#include "../../include/classes/Curso/Leccion.h"
#include "../../include/classes/Curso/Curso.h"

#include "../enums/NIVEL.h"

using namespace std;

class IControladorCurso {
    public:
        
        
        virtual set<string> obtenerCursos() = 0;
        virtual string getNombreCurso() = 0;
        virtual set<string> getDataCurso() = 0;
        virtual string getNickProfesor() = 0;
        virtual set<string> getNombresCursosPrevios() = 0;
        virtual set<DTDataLeccion> getLecciones() = 0;
        virtual void eliminarCurso(string nombre) = 0;
        virtual void setLeccionActual(Leccion *leccion) = 0;
        
        virtual void ingresarNicknameEstudiante(string nomEstudiante) = 0;
        virtual set<string> listarCursosInscrip() = 0;
        virtual set<string> mostrarCursosNoAprobados() = 0;
        virtual set<string> mostrarEjerciciosNoAprobados() = 0;
        virtual DTEjercicio seleccionarEjercicio(string nombreEjercicio) = 0;
        virtual void ingresarSolucionCompletar(set<string> solC) = 0;
        virtual void ingresarSolucionTraducir(string solT) = 0;
        virtual void marcarEjercicioAprobado() = 0;
        virtual void marcarEjercicioNoAprobado() = 0;
        virtual ~IControladorCurso() {};

        //Operaciones para Consulta Curso
        virtual set<string> listarNombreCursos() = 0;
        virtual DTDataCurso* mostrarDatosCurso() = 0; 

        //Operaciones para Alta Curso
        virtual void seleccionarProfesor(string nickname) = 0;
        virtual void ingresarDatosCurso(string nombre, string descripcion, Nivel dificultad) = 0;
        virtual void seleccionarIdioma(string nombreIdioma) = 0;
        virtual set<string> listarCursosHabilitados() = 0;
        virtual void seleccionarCurso(string nombreCurso) = 0;
        virtual void agregarLeccion(string tema, string objetivo) = 0;
        virtual void agregarEjercicio(string nombre, string tipoEjercicio, string descEjercicio) = 0;
        virtual void altaCurso(bool disponible) = 0;

        virtual void agregarFraseTraducir(string fraseATraducir, string fraseTraducida) = 0;
        virtual void agregarFraseCompletar(string fraseACompletar, vector<string> palabras) = 0;

        virtual void agregarLeccionACurso(Leccion *leccion) = 0;

        virtual vector<string> listarLecciones(Curso *curso) = 0;
        virtual void darDeAltaCompletar(string descripcion, string fraseACompletar, vector<string> palabrasFaltantes) = 0;
        virtual void darDeAltaTraducir(string descripcion, string fraseATraducir, string fraseTraducida) = 0;

        //operaciones para habilitar curso
        virtual set<string> listarCursosNoHabilitados()=0;



};

#endif