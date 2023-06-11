#ifndef DTESTUDIANTE
#define DTESTUDIANTE

#include <string>

#include "DTUsuario.h"

#include "../datatypes/DTDate.h"

using namespace std;

class DTEstudiante : public DTUsuario {
private:
    string pais;
    DTDate* fechaNacimiento;

public:
    
        // Constructor
        DTEstudiante();
        DTEstudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, DTDate *fechaNacimiento);
    
        // Getters
        string getPais();
        DTDate* getFechaNacimiento();
    
        // Destructor
        ~DTEstudiante();

        void imprimir(ostream& os);
    };

#endif