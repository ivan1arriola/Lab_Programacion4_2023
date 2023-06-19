/*nombre: String
descripcion: String*/

#ifndef EJERCICIO
#define EJERCICIO

#include <string>
#include "../../datatypes/DTEjercicio.h"

using namespace std;

class Ejercicio {
    private:
        string descripcion;
    public:
        Ejercicio();
        Ejercicio(string descripcion);

        // Getters
        string getDescripcion();
        DTEjercicio *getDTEjercicio();

        // Setters
        void setDescripcion(string descripcion);

        virtual ~Ejercicio();

};

#endif