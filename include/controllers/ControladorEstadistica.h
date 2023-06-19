#ifndef CONTROLADORESTADISTICA_H
#define CONTROLADORESTADISTICA_H

#include <set>
#include <vector>
#include <map>
#include <vector>

#include "../interfaces/IControladorEstadistica.h"
#include "../../include/classes/Curso/Leccion.h"
#include "../datatypes/DTDataCursoEstudiante.h"
#include "../datatypes/DTDataCursoProfesor.h"
#include "../datatypes/DTDataInfoCurso.h"

using namespace std;

class ControladorEstadistica : public IControladorEstadistica {
private:

    static ControladorEstadistica* instancia;

    string actual_nickname;
    string nombreCurso;
    vector<Leccion *> leccionesCursoActual;

    ControladorEstadistica();

public:
    static IControladorEstadistica* getInstancia();

    // Operaciones
    set<string> listarNicknameEstudiantes();
    set<DTDataCursoEstudiante*> listarCursosEstudiante();
    void seleccionarEstudiante(string nicknameEstudiante);
    set<string> listarNIcknameProfesores();
    void seleccionarProfesor(string nicknameProfesor);
    set<DTDataCursoProfesor*> listarCursosProfesor();
    set<string> obtenerCursos();
    void seleccionarCurso(string nombreCurso);
    DTDataInfoCurso* listarInfoCurso();

    ~ControladorEstadistica();  // Destructor
};

#endif
