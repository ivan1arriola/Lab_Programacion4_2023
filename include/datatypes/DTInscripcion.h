#ifndef DTINSCRIPCION
#define DTINSCRIPCION

#include <string>
#include "../datatypes/DTDate.h"


using namespace std;

class DTInscripcion {
private:
    string nicknameEstudiante;
    DTDate *fechaInscripcion;

public:
    //Constructores
    DTInscripcion();
    DTInscripcion(string nicknameEstudiante, DTDate *fechaInscripcion);

    //Getters
    string getNicknameEstudiante();
    DTDate* getFechaInscripcion();

    //Destructor
    ~DTInscripcion();

    friend ostream& operator<<(ostream& os, const DTInscripcion& dtInscripcion);

};

#endif
