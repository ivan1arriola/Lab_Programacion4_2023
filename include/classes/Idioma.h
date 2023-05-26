#ifndef IDIOMA
#define IDIOMA

#include <string>
#include '../interfaces/ISuscriptor.h'

using namespace std;

class Idioma {
    private:
        string nombre;
    public:
        virtual Idioma() {};
        virtual string getNombre() = 0;
        virtual ~Idioma() {}

        virtual void agregarSuscriptor(ISuscriptor suscriptor) = 0;
        virtual void eliminarSuscriptor(string nickname) = 0;
        virtual void notificarSuscriptores() = 0;

        virtual bool contieneSuscriptor(string nickname) = 0;
        virtual set<string> getIdiomasProfesor() = 0;

};

#endif