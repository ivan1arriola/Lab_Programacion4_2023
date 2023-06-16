/*nombre: String
descripcion: String*/

#ifndef EJERCICIO
#define EJERCICIO

#include <string>
// #include "Traducir.h"
// #include "Completar.h"

using namespace std;

class Ejercicio {
    private:
        string nombre;
        string descripcion;
    public:
        Ejercicio();
        Ejercicio(string nombre, string descripcion);

        // Getters
        string getNombre();
        string getDescripcion();

        // Setters
        void setNombre(string nombre);
        void setDescripcion(string descripcion);

        virtual ~Ejercicio();

};

#endif