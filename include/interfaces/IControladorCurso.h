#ifndef ICONTROLADORCURSO
#define ICONTROLADORCURSO

#include <string>
#include <set>

#include "../datatypes/DTDataCurso.h"
#include "../datatypes/DTDataLeccion.h"
#include "../datatypes/DTEjercicio.h"

using namespace std;

class IControladorCurso {
    public:
        virtual set<string> listarCursosHabilitados() = 0;
        virtual void seleccionarIdioma(string nombreIdioma) = 0;
        virtual void seleccionarCurso(string nombreCurso) = 0;
        virtual void altaCurso(bool disponible) = 0;
        virtual set<string> obtenerCursos() = 0;
        virtual string getNombreCurso() = 0;
        virtual set<string> getDataCurso() = 0;
        virtual string getNickProfesor() = 0;
        virtual set<string> getNombresCursosPrevios() = 0;
        virtual set<DTDataLeccion> getLecciones() = 0;
        virtual void eliminarCurso(string nombre) = 0;
        virtual void agregarLeccion(string tema, string objetivo) = 0;
        virtual void agregarEjercicio(string tipoEjercicio, string descEjercicio) = 0;
        virtual void ingresarNicknameEstudiante(string nomEstudiante) = 0;
        virtual void ingresarDatosCurso(string nombre, string desc, string dificultad) = 0;
        virtual set<string> listarCursosInscrip() = 0;
        virtual set<string> mostrarCursosNoAprobados() = 0;
        virtual set<string> mostrarEjerciciosNoAprobados() = 0;
        virtual DTEjercicio seleccionarEjercicio(string nombreEjercicio) = 0;
        virtual void ingresarSolucionCompletar(set<string> solC) = 0;
        virtual void ingresarSolucionTraducir(string solT) = 0;
        virtual void marcarEjercicioAprobado() = 0;
        virtual void marcarEjercicioNoAprobado() = 0;
        virtual ~IControladorCurso() {};
};

#endif