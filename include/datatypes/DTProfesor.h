#ifndef DTPROFESOR
#define DTPROFESOR

#include <string>

#include "DTUsuario.h"

using namespace std;


class DTProfesor : public DTUsuario {
private:
    string instituto;
public:
        // Constructor
        DTProfesor();
        DTProfesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto);
    
        // Getters
        string getInstituto();
    
        // Destructor
        ~DTProfesor();

        void imprimir(ostream& os);
    };

#endif