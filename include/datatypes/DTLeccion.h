#ifndef DTLECCION
#define DTLECCION

#include <string>
#include <iostream>

using namespace std;

class DTLeccion {
    private:
        string tema;
        string objetivo;
    public:
        DTLeccion();
        DTLeccion(string tema, string objetivo);

        string getTema();
        string getObjetivo();

        ~DTLeccion();

        friend 

}

#endif