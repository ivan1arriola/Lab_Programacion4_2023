#ifndef DTDATACURSO
#define DTDATACURSO

#include <string>

#include "../enums/NIVEL.h"


using namespace std;

class DTDataCurso {
    private:
        string nombre;
        string descripcion;
        Nivel nivel;
        bool disponible;

        string nombreIdioma;
        string nombreProfesor;
    public:
        DTDataCurso();
        DTDataCurso(string nombre, string descripcion, Nivel nivel, bool disponible, string nombreIdioma, string nombreProfesor);

        //Getters
        string getNombre();
        string getDescripcion();
        string getNivel();
        string getDisponible();
        string getNombreIdioma();
        string getNombreProfesor();


        ~DTDataCurso();
};

#endif