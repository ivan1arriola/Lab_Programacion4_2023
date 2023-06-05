/*nombre: String
descripcion: String*/

#ifndef EJERCICIO
#define EJERCICIO

#include <string>

using namespace std;

class Ejercicio {
    private:
        string nombre;
        string descripcion;
    public:
        Ejercicio();
        Ejercicio(string nombre, string descripcion);

        // Getters
        virtual string getNombre()=0;
        virtual string getDescripcion()=0;

        // Setters
        virtual void setNombre(string nombre)=0;
        virtual void setDescripcion(string descripcion)=0;

        virtual ~Ejercicio()=0;

};

#endif