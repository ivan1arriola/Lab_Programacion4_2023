/* tema:String
objetivo:String*/

#ifndef DTDATALECCION
#define DTDATALECCION

#include <string>

using namespace std;

class DTDataLeccion {
    private:
        string tema;
        string objetivo;
    public:
        DTDataLeccion(string tema, string objetivo);
        string getTema();
        string getObjetivo();
        ~DTDataLeccion();
};

#endif