#ifndef CONTROLADORESTADISTICA_H
#define CONTROLADORESTADISTICA_H

#include <set>

#include "../interfaces/IControladorEstadistica.h"
#include "../datatypes/DTDataCursoEstudiante.h"

class ControladorEstadistica : public IControladorEstadistica {
private:

    static ControladorEstadistica* instancia;

    ControladorEstadistica();

public:
    static IControladorEstadistica* getInstancia();

    // Operaciones
    set<string> listarNicknameEstudiantes();
    set<DTDataCursoEstudiante> listarCursosEstudiante(string nicknameE);

    ~ControladorEstadistica();  // Destructor
};

#endif
