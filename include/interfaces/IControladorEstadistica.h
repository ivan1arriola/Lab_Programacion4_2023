#ifndef ICONTROLADORESTADISTICA
#define ICONTROLADORESTADISTICA

#include <string>
#include <set>

#include "../datatypes/DTDataCursoEstudiante.h"

using namespace std;

class IControladorEstadistica {
    public:
        virtual set<string> listarNicknameEstudiantes() = 0;
        virtual set<DTDataCursoEstudiante> listarCursosEstudiante(string nicknameE) = 0;
        virtual ~IControladorEstadistica() {};
};

#endif