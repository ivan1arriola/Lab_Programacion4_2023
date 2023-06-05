#ifndef IDIOMA
#define IDIOMA

#include <string>
#include <set>
#include "../interfaces/ISuscriptor.h"

using namespace std;

class Idioma {
    private:
        string nombre;
        //set<ISuscriptor> suscriptores;
    public:
        Idioma();
        Idioma(string nombre);
        string getNombre();
        ~Idioma();

        void agregarSuscriptor(ISuscriptor* suscriptor);
        void eliminarSuscriptor(string nickname);
        void notificarSuscriptores();

        bool contieneSuscriptor(string nickname);
        set<string> getIdiomasProfesor();

        bool operator==(const Idioma& otro);

};

#endif