#ifndef DTPROFESOR
#define DTPROFESOR

#include <string>
#include <set>

#include "DTUsuario.h"

using namespace std;


class DTProfesor : public DTUsuario {
private:
    string instituto;
    set<string> idiomas; 

public:
        // Constructor
        DTProfesor();
        DTProfesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto);
        DTProfesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto, set<string> idiomas);
    
        // Getters
        string getInstituto();
        set<string> getIdiomas();
    
        // Destructor
        ~DTProfesor();

        friend ostream& operator<<(ostream& os, DTProfesor& dtProfesor);
    };

#endif