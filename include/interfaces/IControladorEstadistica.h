#ifndef ICONTROLADORESTADISTICA
#define ICONTROLADORESTADISTICA

#include <string>
#include <set>

#include "../datatypes/DTDataCursoEstudiante.h"
#include "../datatypes/DTDataCursoProfesor.h"
#include "../datatypes/DTDataInfoCurso.h"

using namespace std;

class IControladorEstadistica {
    public:
        virtual set<string> listarNicknameEstudiantes() = 0;
        virtual set<DTDataCursoEstudiante*> listarCursosEstudiante() = 0;
        virtual void seleccionarEstudiante(string nicknameEstudiante) = 0;
        virtual set<string> listarNIcknameProfesores() = 0;
        virtual void seleccionarProfesor(string nicknameProfesor) = 0;
        virtual set<DTDataCursoProfesor*> listarCursosProfesor() = 0;
        virtual set<string> obtenerCursos() = 0;
        virtual void seleccionarCurso(string nombreCurso) = 0;
        virtual DTDataInfoCurso* listarInfoCurso() = 0;
        virtual ~IControladorEstadistica() {};
};

#endif