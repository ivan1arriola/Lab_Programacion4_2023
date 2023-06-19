/* tema:String
objetivo:String*/

#ifndef DTDATALECCION
#define DTDATALECCION

#include <string>
#include <set>

#include "DTEjercicio.h"

using namespace std;

class DTDataLeccion {
    private:
        string tema;
        string objetivo;
        set<DTEjercicio *> ejercicios;
    public:
        DTDataLeccion(string tema, string objetivo);
        DTDataLeccion(string tema, string objetivo, set<DTEjercicio *> ejercicios);
        string getTema();
        string getObjetivo();
        ~DTDataLeccion();

        friend ostream& operator<<(ostream& os, const DTDataLeccion& dtLeccion);
};

#endif