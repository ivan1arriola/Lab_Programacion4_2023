#ifndef IDIOMA
#define IDIOMA

#include <string>
#include <set>
#include <map>
#include "../interfaces/ISuscriptor.h"

using namespace std;

class Idioma {
    private:
        string nombre;
        map<string, ISuscriptor*> suscriptores; // nickname, puntero a suscriptor
    public:
        Idioma();
        Idioma(string nombre);
        string getNombre();
        ~Idioma();

        void agregarSuscriptor(ISuscriptor* suscriptor);
        void eliminarSuscriptor(string nickname);
        void notificarSuscriptores(string nombreCurso);

        bool contieneSuscriptor(string nickname);
        
        set<string> getIdiomasProfesor();

        bool operator==(const Idioma& otro);

};

#endif